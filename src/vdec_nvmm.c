/**
 * Copyright (c) 2021 Kompilomat, H. Lampesberger
 *
 */
#ifdef BUILD_NVMM

#define ULOG_TAG vdec_nvmm
#include "vdec_priv.h"
ULOG_DECLARE_TAG(vdec_nvmm);







int vdec_videotoolbox_sync_decode(struct vdec_decoder *base,
				  struct vbuf_buffer *in_buf,
				  struct vbuf_buffer **out_buf)
{
	/* Synchronized decoding is not supported */
	print_hello_world(4);
	return -ENOSYS;
}

#endif /* BUILD_NVMM */
