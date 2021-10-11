/**
 * Copyright (c) 2021 Kompilomat, H. Lampesberger
 *
 */

#ifndef _VDEC_NVMM_H_
#define _VDEC_NVMM_H_

struct vdec_nvmm;


#define VDEC_OPS_NVMM                                                       \
	{                                                                      \
		.get_supported_input_format =                                  \
			&vdec_nvmm_get_supported_input_format,               \
		.new = &vdec_nvmm_new, .flush = &vdec_nvmm_flush,          \
		.stop = &vdec_nvmm_stop, .destroy = &vdec_nvmm_destroy,    \
		.set_sps_pps = &vdec_nvmm_set_sps_pps,                       \
		.get_input_buffer_pool = &vdec_nvmm_get_input_buffer_pool,   \
		.get_input_buffer_queue = &vdec_nvmm_get_input_buffer_queue, \
		.sync_decode = &vdec_nvmm_sync_decode,                       \
	}


uint32_t vdec_nvmm_get_supported_input_format(void);


int vdec_nvmm_new(struct vdec_decoder *base);


int vdec_nvmm_flush(struct vdec_decoder *base, int discard);


int vdec_nvmm_stop(struct vdec_decoder *base);


int vdec_nvmm_destroy(struct vdec_decoder *base);


int vdec_nvmm_set_sps_pps(struct vdec_decoder *base,
			    const uint8_t *sps,
			    size_t sps_size,
			    const uint8_t *pps,
			    size_t pps_size,
			    enum vdec_input_format format);


struct vbuf_pool *vdec_nvmm_get_input_buffer_pool(struct vdec_decoder *base);


struct vbuf_queue *
vdec_nvmm_get_input_buffer_queue(struct vdec_decoder *base);


int vdec_nvmm_sync_decode(struct vdec_decoder *base,
			    struct vbuf_buffer *in_buf,
			    struct vbuf_buffer **out_buf);




/* function signatures of extern "C" definitions in vdec_nvmm_wrapper.cpp */


#endif /* !_VDEC_NVMM_H_ */
