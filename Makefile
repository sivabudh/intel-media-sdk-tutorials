EXAMPLEDIRS = \
	simple_1_session \
	simple_2_decode \
	simple_2_decode_vmem \
	simple_3_encode \
	simple_3_encode_vmem \
	simple_3_encode_vmem_async \
	simple_4_vpp_resize_denoise \
	simple_4_vpp_resize_denoise_vmem \
	simple_5_transcode \
	simple_5_transcode_opaque \
	simple_5_transcode_opaque_async \
	simple_5_transcode_opaque_async_vppresize \
	simple_5_transcode_vmem \
	simple_6_decode_vpp_postproc \
	simple_6_encode_vmem_lowlatency \
	simple_6_encode_vmem_vpp_preproc \
	simple_6_transcode_opaque_lowlatency

all:
	@for dir in $(EXAMPLEDIRS); do \
		echo $$dir; \
		(cd $$dir; make); \
	done

.PHONY: clean
clean:
	@for dir in $(EXAMPLEDIRS); do \
		echo $$dir; \
		(cd $$dir; make clean); \
	done
