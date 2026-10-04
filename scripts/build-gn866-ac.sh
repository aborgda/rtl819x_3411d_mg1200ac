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

# The GN866-specific config files are kept in the repository-level
# boards/ tree; copy them into the active SDK board tree before build.
for f in \
  "config.linux-$LINUX.$MODEL" \
  "config.users.$MODEL" \
  "config.$BZBOX.$MODEL"
do
  test -f "$CUSTOM/$f"
  cp -f "$CUSTOM/$f" "boards/$BOARD/$f"
done

rm -f target image romfs tmpfs users/busybox
ln -s "boards/$BOARD" target
mkdir -p target/tmpfs target/romfs target/image
ln -s target/tmpfs tmpfs
ln -s target/romfs romfs
ln -s target/image image
ln -s "users/$BZBOX" users/busybox

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
EOF

cp -f "boards/$BOARD/config.linux-$LINUX.$MODEL" "linux-$LINUX/.config"
cp -f "boards/$BOARD/config.users.$MODEL" users/.config
cp -f "boards/$BOARD/config.$BZBOX.$MODEL" "users/$BZBOX/.config"

export PATH="$PWD/toolchain/$RSDK/bin:$PATH"

echo "Configuration:"
grep -E '^CONFIG_(BOARD|LINUX|BZBOX|RSDK|MODEL|ROUTER|RSDKDIR|BOARDDIR|LINUXDIR|BZBOXDIR)=' .config

echo "Toolchain:"
command -v msdk-linux-gcc
msdk-linux-gcc --version | head -1

echo "Build:"
make -j"${JOBS:-2}" V=1

echo "Images:"
find target/image -maxdepth 1 -type f -printf '%f %s bytes\n' 2>/dev/null || true
