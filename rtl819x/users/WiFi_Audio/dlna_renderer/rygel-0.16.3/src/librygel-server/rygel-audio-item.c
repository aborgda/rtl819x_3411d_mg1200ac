/* rygel-audio-item.c generated by valac 0.16.1, the Vala compiler
 * generated from rygel-audio-item.vala, do not modify */

/*
 * Copyright (C) 2008 Zeeshan Ali <zeenix@gmail.com>.
 * Copyright (C) 2010 Nokia Corporation.
 *
 * Author: Zeeshan Ali (Khattak) <zeeshanak@gnome.org>
 *                               <zeeshan.ali@nokia.com>
 *
 * This file is part of Rygel.
 *
 * Rygel is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Rygel is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include <glib.h>
#include <glib-object.h>
#include <libgupnp-av/gupnp-av.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>
#include <gst/gst.h>


#define RYGEL_TYPE_MEDIA_OBJECT (rygel_media_object_get_type ())
#define RYGEL_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObject))
#define RYGEL_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))
#define RYGEL_IS_MEDIA_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_IS_MEDIA_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_OBJECT))
#define RYGEL_MEDIA_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_OBJECT, RygelMediaObjectClass))

typedef struct _RygelMediaObject RygelMediaObject;
typedef struct _RygelMediaObjectClass RygelMediaObjectClass;
typedef struct _RygelMediaObjectPrivate RygelMediaObjectPrivate;

#define RYGEL_TYPE_TRANSCODE_MANAGER (rygel_transcode_manager_get_type ())
#define RYGEL_TRANSCODE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_TRANSCODE_MANAGER, RygelTranscodeManager))
#define RYGEL_TRANSCODE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_TRANSCODE_MANAGER, RygelTranscodeManagerClass))
#define RYGEL_IS_TRANSCODE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_TRANSCODE_MANAGER))
#define RYGEL_IS_TRANSCODE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_TRANSCODE_MANAGER))
#define RYGEL_TRANSCODE_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_TRANSCODE_MANAGER, RygelTranscodeManagerClass))

typedef struct _RygelTranscodeManager RygelTranscodeManager;
typedef struct _RygelTranscodeManagerClass RygelTranscodeManagerClass;

#define RYGEL_TYPE_HTTP_SERVER (rygel_http_server_get_type ())
#define RYGEL_HTTP_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_HTTP_SERVER, RygelHTTPServer))
#define RYGEL_HTTP_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_HTTP_SERVER, RygelHTTPServerClass))
#define RYGEL_IS_HTTP_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_HTTP_SERVER))
#define RYGEL_IS_HTTP_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_HTTP_SERVER))
#define RYGEL_HTTP_SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_HTTP_SERVER, RygelHTTPServerClass))

typedef struct _RygelHTTPServer RygelHTTPServer;
typedef struct _RygelHTTPServerClass RygelHTTPServerClass;

#define RYGEL_TYPE_MEDIA_CONTAINER (rygel_media_container_get_type ())
#define RYGEL_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainer))
#define RYGEL_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))
#define RYGEL_IS_MEDIA_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_IS_MEDIA_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_CONTAINER))
#define RYGEL_MEDIA_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_CONTAINER, RygelMediaContainerClass))

typedef struct _RygelMediaContainer RygelMediaContainer;
typedef struct _RygelMediaContainerClass RygelMediaContainerClass;

#define RYGEL_TYPE_MEDIA_ITEM (rygel_media_item_get_type ())
#define RYGEL_MEDIA_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItem))
#define RYGEL_MEDIA_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItemClass))
#define RYGEL_IS_MEDIA_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_MEDIA_ITEM))
#define RYGEL_IS_MEDIA_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_MEDIA_ITEM))
#define RYGEL_MEDIA_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_MEDIA_ITEM, RygelMediaItemClass))

typedef struct _RygelMediaItem RygelMediaItem;
typedef struct _RygelMediaItemClass RygelMediaItemClass;
typedef struct _RygelMediaItemPrivate RygelMediaItemPrivate;

#define RYGEL_TYPE_AUDIO_ITEM (rygel_audio_item_get_type ())
#define RYGEL_AUDIO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RYGEL_TYPE_AUDIO_ITEM, RygelAudioItem))
#define RYGEL_AUDIO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RYGEL_TYPE_AUDIO_ITEM, RygelAudioItemClass))
#define RYGEL_IS_AUDIO_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RYGEL_TYPE_AUDIO_ITEM))
#define RYGEL_IS_AUDIO_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RYGEL_TYPE_AUDIO_ITEM))
#define RYGEL_AUDIO_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RYGEL_TYPE_AUDIO_ITEM, RygelAudioItemClass))

typedef struct _RygelAudioItem RygelAudioItem;
typedef struct _RygelAudioItemClass RygelAudioItemClass;
typedef struct _RygelAudioItemPrivate RygelAudioItemPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _RygelMediaObject {
	GObject parent_instance;
	RygelMediaObjectPrivate * priv;
	gchar* id;
	gchar* ref_id;
	gchar* upnp_class;
	guint64 modified;
	GeeArrayList* uris;
	RygelMediaContainer* parent;
};

struct _RygelMediaObjectClass {
	GObjectClass parent_class;
	GUPnPDIDLLiteObject* (*serialize) (RygelMediaObject* self, GUPnPDIDLLiteWriter* writer, RygelHTTPServer* http_server, GError** error);
	gint (*compare_by_property) (RygelMediaObject* self, RygelMediaObject* media_object, const gchar* property);
	GUPnPOCMFlags (*get_ocm_flags) (RygelMediaObject* self);
};

struct _RygelMediaItem {
	RygelMediaObject parent_instance;
	RygelMediaItemPrivate * priv;
	gchar* date;
	gchar* mime_type;
	gchar* dlna_profile;
	GRegex* address_regex;
};

struct _RygelMediaItemClass {
	RygelMediaObjectClass parent_class;
	GstElement* (*create_stream_source) (RygelMediaItem* self, const gchar* host_ip);
	gboolean (*streamable) (RygelMediaItem* self);
	void (*add_uri) (RygelMediaItem* self, const gchar* uri);
	GUPnPDIDLLiteResource* (*add_resource) (RygelMediaItem* self, GUPnPDIDLLiteItem* didl_item, const gchar* uri, const gchar* protocol, const gchar* import_uri, GError** error);
	void (*add_proxy_resources) (RygelMediaItem* self, RygelHTTPServer* server, GUPnPDIDLLiteItem* didl_item, GError** error);
	GUPnPProtocolInfo* (*get_protocol_info) (RygelMediaItem* self, const gchar* uri, const gchar* protocol);
	void (*add_resources) (RygelMediaItem* self, GUPnPDIDLLiteItem* didl_item, gboolean allow_internal, GError** error);
};

struct _RygelAudioItem {
	RygelMediaItem parent_instance;
	RygelAudioItemPrivate * priv;
	glong duration;
	gint bitrate;
	gint sample_freq;
	gint bits_per_sample;
	gint channels;
};

struct _RygelAudioItemClass {
	RygelMediaItemClass parent_class;
};


static gpointer rygel_audio_item_parent_class = NULL;

GType rygel_media_object_get_type (void) G_GNUC_CONST;
GType rygel_transcode_manager_get_type (void) G_GNUC_CONST;
GType rygel_http_server_get_type (void) G_GNUC_CONST;
GType rygel_media_container_get_type (void) G_GNUC_CONST;
GType rygel_media_item_get_type (void) G_GNUC_CONST;
GType rygel_audio_item_get_type (void) G_GNUC_CONST;
enum  {
	RYGEL_AUDIO_ITEM_DUMMY_PROPERTY
};
#define RYGEL_AUDIO_ITEM_UPNP_CLASS "object.item.audioItem"
RygelAudioItem* rygel_audio_item_new (const gchar* id, RygelMediaContainer* parent, const gchar* title, const gchar* upnp_class);
RygelAudioItem* rygel_audio_item_construct (GType object_type, const gchar* id, RygelMediaContainer* parent, const gchar* title, const gchar* upnp_class);
RygelMediaItem* rygel_media_item_construct (GType object_type, const gchar* id, RygelMediaContainer* parent, const gchar* title, const gchar* upnp_class);
static gboolean rygel_audio_item_real_streamable (RygelMediaItem* base);
static GUPnPDIDLLiteResource* rygel_audio_item_real_add_resource (RygelMediaItem* base, GUPnPDIDLLiteItem* didl_item, const gchar* uri, const gchar* protocol, const gchar* import_uri, GError** error);
GUPnPDIDLLiteResource* rygel_media_item_add_resource (RygelMediaItem* self, GUPnPDIDLLiteItem* didl_item, const gchar* uri, const gchar* protocol, const gchar* import_uri, GError** error);
static void rygel_audio_item_finalize (GObject* obj);


RygelAudioItem* rygel_audio_item_construct (GType object_type, const gchar* id, RygelMediaContainer* parent, const gchar* title, const gchar* upnp_class) {
	RygelAudioItem * self = NULL;
	const gchar* _tmp0_;
	RygelMediaContainer* _tmp1_;
	const gchar* _tmp2_;
	const gchar* _tmp3_;
	g_return_val_if_fail (id != NULL, NULL);
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (title != NULL, NULL);
	g_return_val_if_fail (upnp_class != NULL, NULL);
	_tmp0_ = id;
	_tmp1_ = parent;
	_tmp2_ = title;
	_tmp3_ = upnp_class;
	self = (RygelAudioItem*) rygel_media_item_construct (object_type, _tmp0_, _tmp1_, _tmp2_, _tmp3_);
	return self;
}


RygelAudioItem* rygel_audio_item_new (const gchar* id, RygelMediaContainer* parent, const gchar* title, const gchar* upnp_class) {
	return rygel_audio_item_construct (RYGEL_TYPE_AUDIO_ITEM, id, parent, title, upnp_class);
}


static gboolean rygel_audio_item_real_streamable (RygelMediaItem* base) {
	RygelAudioItem * self;
	gboolean result = FALSE;
	self = (RygelAudioItem*) base;
	result = TRUE;
	return result;
}


static GUPnPDIDLLiteResource* rygel_audio_item_real_add_resource (RygelMediaItem* base, GUPnPDIDLLiteItem* didl_item, const gchar* uri, const gchar* protocol, const gchar* import_uri, GError** error) {
	RygelAudioItem * self;
	GUPnPDIDLLiteResource* result = NULL;
	GUPnPDIDLLiteItem* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	const gchar* _tmp3_;
	GUPnPDIDLLiteResource* _tmp4_ = NULL;
	GUPnPDIDLLiteResource* res;
	glong _tmp5_;
	gint _tmp6_;
	gint _tmp7_;
	gint _tmp8_;
	gint _tmp9_;
	GError * _inner_error_ = NULL;
	self = (RygelAudioItem*) base;
	g_return_val_if_fail (didl_item != NULL, NULL);
	g_return_val_if_fail (protocol != NULL, NULL);
	_tmp0_ = didl_item;
	_tmp1_ = uri;
	_tmp2_ = protocol;
	_tmp3_ = import_uri;
	_tmp4_ = RYGEL_MEDIA_ITEM_CLASS (rygel_audio_item_parent_class)->add_resource (RYGEL_MEDIA_ITEM (self), _tmp0_, _tmp1_, _tmp2_, _tmp3_, &_inner_error_);
	res = _tmp4_;
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	}
	_tmp5_ = self->duration;
	gupnp_didl_lite_resource_set_duration (res, _tmp5_);
	_tmp6_ = self->bitrate;
	gupnp_didl_lite_resource_set_bitrate (res, _tmp6_);
	_tmp7_ = self->sample_freq;
	gupnp_didl_lite_resource_set_sample_freq (res, _tmp7_);
	_tmp8_ = self->bits_per_sample;
	gupnp_didl_lite_resource_set_bits_per_sample (res, _tmp8_);
	_tmp9_ = self->channels;
	gupnp_didl_lite_resource_set_audio_channels (res, _tmp9_);
	result = res;
	return result;
}


static void rygel_audio_item_class_init (RygelAudioItemClass * klass) {
	rygel_audio_item_parent_class = g_type_class_peek_parent (klass);
	RYGEL_MEDIA_ITEM_CLASS (klass)->streamable = rygel_audio_item_real_streamable;
	RYGEL_MEDIA_ITEM_CLASS (klass)->add_resource = rygel_audio_item_real_add_resource;
	G_OBJECT_CLASS (klass)->finalize = rygel_audio_item_finalize;
}


static void rygel_audio_item_instance_init (RygelAudioItem * self) {
	self->duration = (glong) (-1);
	self->bitrate = -1;
	self->sample_freq = -1;
	self->bits_per_sample = -1;
	self->channels = -1;
}


static void rygel_audio_item_finalize (GObject* obj) {
	RygelAudioItem * self;
	self = RYGEL_AUDIO_ITEM (obj);
	G_OBJECT_CLASS (rygel_audio_item_parent_class)->finalize (obj);
}


/**
 * Represents an audio item.
 */
GType rygel_audio_item_get_type (void) {
	static volatile gsize rygel_audio_item_type_id__volatile = 0;
	if (g_once_init_enter (&rygel_audio_item_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RygelAudioItemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rygel_audio_item_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RygelAudioItem), 0, (GInstanceInitFunc) rygel_audio_item_instance_init, NULL };
		GType rygel_audio_item_type_id;
		rygel_audio_item_type_id = g_type_register_static (RYGEL_TYPE_MEDIA_ITEM, "RygelAudioItem", &g_define_type_info, 0);
		g_once_init_leave (&rygel_audio_item_type_id__volatile, rygel_audio_item_type_id);
	}
	return rygel_audio_item_type_id__volatile;
}



