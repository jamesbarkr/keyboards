USER = connorbarkr

KEYBOARDS = dactyl skeletyl kyria dilemma
PATH_dactyl = handwired/dactyl_manuform/5x6_5
PATH_skeletyl = bastardkb/skeletyl
PATH_dilemma = bastardkb/dilemma/3x5_3
PATH_kyria = splitkb/kyria

all: $(KEYBOARDS)

.PHONY: $(KEYBOARDS)
$(KEYBOARDS):
	# init submodule
	# git submodule update --init --recursive

	# cleanup old symlinks
	for f in $(KEYBOARDS); do rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER); done
	rm -rf qmk_firmware/users/$(USER)

	# add new symlinks
	ln -s $(shell pwd)/user qmk_firmware/users/$(USER)
	ln -s $(shell pwd)/$@ qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER)

	# run lint check
	cd qmk_firmware; qmk lint -km $(USER) -kb $(PATH_$@) --strict

	# run build
	make BUILD_DIR=$(shell pwd) -j1 -C qmk_firmware $(PATH_$@):$(USER)

	# cleanup symlinks
	for f in $(KEYBOARDS); do rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER); done
	rm -rf qmk_firmware/users/$(USER)

clean:
	rm -rf obj_*
	rm -f *.elf
	rm -f *.map
	rm -f *.hex