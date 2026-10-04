#!/bin/sh
set -eu

REPO_ROOT="$(CDPATH= cd -- "$(dirname "$0")/.." && pwd)"
SDK="$REPO_ROOT/rtl819x"

BOARD="rtl8198C_8954E"
MODEL="RTL8198C_GN866_AC"
LINUX="3.10"
BZBOX="busybox-1.13"
RSDK="msdk-4.4.7-mips-EB-3.10-0.9.33-m32t-131227b"
CUSTOM="$REPO_ROOT/boards/$BOARD"

cd "$SDK"

echo "GN866 AC build"
echo "SDK: $SDK"
echo "BOARD: $BOARD"
echo "MODEL: $MODEL"

# Install the GN866-specific model configs into the active SDK board tree.
for f in \
  "config.linux-$LINUX.$MODEL" \
  "config.users.$MODEL" \
  "config.$BZBOX.$MODEL"
do
  test -f "$CUSTOM/$f"
  cp -f "$CUSTOM/$f" "boards/$BOARD/$f"
done

cat > .config <<EOF
CONFIG_BOARD_$BOARD=y
CONFIG_LINUX_$LINUX=y
CONFIG_BZBOX_$BZBOX=y
CONFIG_RSDK_$RSDK=y
CONFIG_MODEL_$MODEL=y
CONFIG_LINUXDIR=linux-$LINUX
CONFIG_BOARDDIR=boards/$BOARD
CONFIG_BZBOXDIR=users/$BZBOX
CONFIG_RSDKDIR=toolchain/$RSDK
CONFIG_MODEL=$MODEL
CONFIG_ROUTER=GW
CONFIG_ARCH_CPU_MIPS=y
EOF

# The SDK's own Makefiles use msdk-linux-* while a few legacy users
# components still request rsdk-linux-*.  Provide compatibility aliases.
for tool in "$RSDK"/bin/msdk-linux-*; do
  [ -e "$tool" ] || continue
  name="$(basename "$tool")"
  suffix="${name#msdk-linux-}"
  ln -sf "$name" "$RSDK/bin/rsdk-linux-$suffix"
done

export PATH="$PWD/$RSDK/bin:$PATH"
export CROSS_TARGET=mips-linux
export CROSS_COMPILE=msdk-linux-

# Let the SDK create target/romfs/image/users/busybox and select etc.default
# exactly as its normal configuration flow does.  No menuconfig is used.
chmod +x config/setconfig config/hdrconfig
./config/setconfig defaults
./config/hdrconfig "$PWD"

# Recreate compatibility aliases after SDK cleanup/oldconfig and keep the
# real bundled compiler as the default for users and BusyBox builds.
export CROSS_TARGET=mips-linux
export CROSS_COMPILE=msdk-linux-
for tool in "$RSDK"/bin/msdk-linux-*; do
  [ -e "$tool" ] || continue
  name="$(basename "$tool")"
  suffix="${name#msdk-linux-}"
  ln -sf "$name" "$RSDK/bin/rsdk-linux-$suffix"
done

echo "Configuration:"
grep -E '^CONFIG_(BOARD|LINUX|BZBOX|RSDK|MODEL|ROUTER|RSDKDIR|BOARDDIR|LINUXDIR|BZBOXDIR)=' .config

echo "Toolchain:"
command -v msdk-linux-gcc
command -v rsdk-linux-gcc
command -v rsdk-linux-ar
msdk-linux-gcc --version | head -1

echo "Build:"
CROSS_TARGET=mips-linux CROSS_COMPILE=msdk-linux- make -j1 V=1

echo "Images:"
find target/image -maxdepth 1 -type f -printf '%f %s bytes\n' 2>/dev/null || true
