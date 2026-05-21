	.section	.text,"ax",@progbits
	.assume	ADL = 1
	.file	"llvm-link"
	.section	.text.__ZN6KeypadC2Ev,"ax",@progbits
	.globl	__ZN6KeypadC2Ev                 ; -- Begin function _ZN6KeypadC2Ev
	.type	__ZN6KeypadC2Ev,@function
__ZN6KeypadC2Ev:                        ; @_ZN6KeypadC2Ev
; %bb.0:
	call	__frameset0
	ld	hl, _keymap
	ld	iy, _keymap+2
	ld.sis	de, 1
	ld.sis	bc, 2
	ld	(hl), c
	inc	hl
	ld	(hl), b
	ld.sis	hl, 4
	ld	(iy), l
	ld	(iy + 1), h
	ld.sis	hl, 8
	ld	iy, _keymap+4
	ld	(iy), l
	ld	(iy + 1), h
	ld	hl, _keymap+6
	ld	(hl), e
	inc	hl
	ld	(hl), d
	ld	hl, _keymap+8
	ld	(hl), e
	inc	hl
	ld	(hl), d
	ld	iy, 0
	ld	bc, 15
	lea	de, iy + 0
	.local	.LBB0_1
.LBB0_1:                                ; =>This Inner Loop Header: Depth=1
	push	de
	pop	hl
	or	a, a
	sbc	hl, bc
	jr	z, .LBB0_3
; %bb.2:                                ;   in Loop: Header=BB0_1 Depth=1
	ld	hl, (ix + 6)
	add	hl, de
	ld	(hl), iy
	ex	de, hl
	ld	de, 3
	add	hl, de
	ex	de, hl
	jr	.LBB0_1
	.local	.LBB0_3
.LBB0_3:
	pop	ix
	ret
	.local	.Lfunc_end0
.Lfunc_end0:
	.size	__ZN6KeypadC2Ev, .Lfunc_end0-__ZN6KeypadC2Ev
                                        ; -- End function
	.section	.text.__ZN6Keypad12getKeyStatesEv,"ax",@progbits
	.globl	__ZN6Keypad12getKeyStatesEv     ; -- Begin function _ZN6Keypad12getKeyStatesEv
	.type	__ZN6Keypad12getKeyStatesEv,@function
__ZN6Keypad12getKeyStatesEv:            ; @_ZN6Keypad12getKeyStatesEv
; %bb.0:
	call	__frameset0
	ld	hl, (ix + 6)
	pop	ix
	ret
	.local	.Lfunc_end1
.Lfunc_end1:
	.size	__ZN6Keypad12getKeyStatesEv, .Lfunc_end1-__ZN6Keypad12getKeyStatesEv
                                        ; -- End function
	.section	.text.__ZN6Keypad4scanEv,"ax",@progbits
	.globl	__ZN6Keypad4scanEv              ; -- Begin function _ZN6Keypad4scanEv
	.type	__ZN6Keypad4scanEv,@function
__ZN6Keypad4scanEv:                     ; @_ZN6Keypad4scanEv
; %bb.0:
	ld	hl, -16
	call	__frameset
	ld	bc, 0
	ld	iy, _keymap
	ld	de, 15
	ld	h, b
	ld	(ix - 2), l
	ld	(ix - 1), h
	.local	.LBB2_1
.LBB2_1:                                ; =>This Inner Loop Header: Depth=1
	push	bc
	pop	hl
	or	a, a
	sbc	hl, de
	jp	z, .LBB2_9
; %bb.2:                                ;   in Loop: Header=BB2_1 Depth=1
	ld	(ix - 5), iy
	ld	de, (iy)
	ld	l, (ix - 2)
	ld	h, (ix - 1)
	ld	(ix - 8), de
	ld	l, d
	ld	(ix - 2), l
	ld	(ix - 1), h
	add.sis	hl, hl
	ld	de, 0
	ld	e, l
	ld	d, h
	ld	hl, -720880
	add	hl, de
	push	de
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	l, e
	ld	h, d
	pop	de
	ld	(ix - 13), l
	ld	(ix - 12), h
	ld	iy, (ix + 6)
	add	iy, bc
	ld	de, (iy)
	sbc	hl, hl
	adc	hl, de
	ld	hl, 1
	jr	z, .LBB2_4
; %bb.3:                                ;   in Loop: Header=BB2_1 Depth=1
	ld	hl, 0
	.local	.LBB2_4
.LBB2_4:                                ;   in Loop: Header=BB2_1 Depth=1
	ld	(ix - 16), hl
	ld	(ix - 11), bc
	ex	de, hl
	ld	de, 1
	or	a, a
	sbc	hl, de
	ld	de, 3
	jr	z, .LBB2_6
; %bb.5:                                ;   in Loop: Header=BB2_1 Depth=1
	ld	de, 0
	.local	.LBB2_6
.LBB2_6:                                ;   in Loop: Header=BB2_1 Depth=1
	ld	l, (ix - 13)
	ld	h, (ix - 12)
                                        ; kill: def $l killed $l killed $hl
	ld	bc, (ix - 8)
	ld	a, c
	and	a, l
	ld	l, a
	or	a, a
	jr	z, .LBB2_8
; %bb.7:                                ;   in Loop: Header=BB2_1 Depth=1
	ld	de, (ix - 16)
	inc	de
	.local	.LBB2_8
.LBB2_8:                                ;   in Loop: Header=BB2_1 Depth=1
	ld	(iy), de
	ld	iy, (ix - 5)
	lea	iy, iy + 2
	ld	hl, (ix - 11)
	ld	de, 3
	add	hl, de
	push	hl
	pop	bc
	ld	de, 15
	jp	.LBB2_1
	.local	.LBB2_9
.LBB2_9:
	ld	sp, ix
	pop	ix
	ret
	.local	.Lfunc_end2
.Lfunc_end2:
	.size	__ZN6Keypad4scanEv, .Lfunc_end2-__ZN6Keypad4scanEv
                                        ; -- End function
	.section	.text._main,"ax",@progbits
	.globl	_main                           ; -- Begin function main
	.type	_main,@function
_main:                                  ; @main
; %bb.0:                                ; %_ZN8Renderer25unregisterRenderingEntityEi.exit
	ld	hl, -219
	call	__frameset
	ld	de, -213
	lea	iy, ix + 0
	add	iy, de
	ld	de, -219
	lea	hl, ix + 0
	add	hl, de
	ld	(hl), iy
	lea	hl, iy + 15
	ld	de, -216
	lea	iy, ix + 0
	add	iy, de
	ld	(iy + 0), hl
	push	hl
	call	__ZN8RendererC2Ev
	pop	hl
	ld	de, -219
	lea	iy, ix + 0
	add	iy, de
	ld	hl, (iy + 0)
	push	hl
	call	__ZN6KeypadC2Ev
	pop	hl
	ld	hl, 6
	push	hl
	call	__Znwj
	push	hl
	pop	iy
	ld	de, -219
	lea	hl, ix + 0
	add	hl, de
	ld	(hl), iy
	pop	hl
	ld	hl, 100
	ld	(iy), hl
	ld	(iy + 3), hl
	ld	hl, 6
	push	hl
	call	__Znwj
	push	hl
	pop	iy
	pop	hl
	ld	hl, 16
	ld	(iy), hl
	ld	(iy + 3), hl
	push	iy
	ld	de, -219
	lea	iy, ix + 0
	add	iy, de
	ld	hl, (iy + 0)
	push	hl
	ld	de, -216
	lea	iy, ix + 0
	add	iy, de
	ld	hl, (iy + 0)
	push	hl
	call	__ZN8Renderer23registerRenderingEntityEP8PositionP10Dimensions
	pop	hl
	pop	hl
	pop	hl
	or	a, a
	sbc	hl, hl
	push	hl
	call	_gfx_FillScreen
	pop	hl
	ld	de, -216
	lea	iy, ix + 0
	add	iy, de
	ld	hl, (iy + 0)
	push	hl
	call	__ZN8Renderer23renderRenderingEntitiesEv
	pop	hl
	call	_gfx_End
	or	a, a
	sbc	hl, hl
	ld	sp, ix
	pop	ix
	ret
	.local	.Lfunc_end3
.Lfunc_end3:
	.size	_main, .Lfunc_end3-_main
                                        ; -- End function
	.section	.text.__ZN8RendererC2Ev,"ax",@progbits
	.globl	__ZN8RendererC2Ev               ; -- Begin function _ZN8RendererC2Ev
	.type	__ZN8RendererC2Ev,@function
__ZN8RendererC2Ev:                      ; @_ZN8RendererC2Ev
; %bb.0:
	call	__frameset0
	ld	hl, (ix + 6)
	ld	(hl), 0
	push	hl
	pop	iy
	inc	iy
	ld	bc, 143
	lea	de, iy + 0
	ldir
	call	_gfx_Begin
	ld	iy, 48
	ld	bc, 0
	.local	.LBB4_1
.LBB4_1:                                ; =>This Inner Loop Header: Depth=1
	push	bc
	pop	hl
	lea	de, iy + 0
	or	a, a
	sbc	hl, de
	jr	z, .LBB4_3
; %bb.2:                                ;   in Loop: Header=BB4_1 Depth=1
	ld	hl, (ix + 6)
	add	hl, bc
	ld	de, 144
	add	hl, de
	ld	de, 0
	ld	(hl), de
	push	bc
	pop	hl
	ld	bc, 3
	add	hl, bc
	push	hl
	pop	bc
	jr	.LBB4_1
	.local	.LBB4_3
.LBB4_3:
	pop	ix
	ret
	.local	.Lfunc_end4
.Lfunc_end4:
	.size	__ZN8RendererC2Ev, .Lfunc_end4-__ZN8RendererC2Ev
                                        ; -- End function
	.section	.text.__ZN8RendererD2Ev,"ax",@progbits
	.globl	__ZN8RendererD2Ev               ; -- Begin function _ZN8RendererD2Ev
	.type	__ZN8RendererD2Ev,@function
__ZN8RendererD2Ev:                      ; @_ZN8RendererD2Ev
; %bb.0:
	call	__frameset0
	pop	ix
	jp	_gfx_End
	.local	.Lfunc_end5
.Lfunc_end5:
	.size	__ZN8RendererD2Ev, .Lfunc_end5-__ZN8RendererD2Ev
                                        ; -- End function
	.section	.text.__ZN8Renderer23registerRenderingEntityEP8PositionP10Dimensions,"ax",@progbits
	.globl	__ZN8Renderer23registerRenderingEntityEP8PositionP10Dimensions ; -- Begin function _ZN8Renderer23registerRenderingEntityEP8PositionP10Dimensions
	.type	__ZN8Renderer23registerRenderingEntityEP8PositionP10Dimensions,@function
__ZN8Renderer23registerRenderingEntityEP8PositionP10Dimensions: ; @_ZN8Renderer23registerRenderingEntityEP8PositionP10Dimensions
; %bb.0:
	ld	hl, -9
	call	__frameset
	ld	iy, (ix + 6)
	ld	bc, 0
	ld	de, 144
	lea	hl, iy + 3
	ld	(ix - 6), hl
	add	iy, de
	ld	(ix - 3), iy
	ld	de, 16
	.local	.LBB6_1
.LBB6_1:                                ; =>This Inner Loop Header: Depth=1
	ld	(ix - 9), bc
	push	bc
	pop	hl
	push	de
	pop	bc
	or	a, a
	sbc	hl, de
	jr	z, .LBB6_4
; %bb.2:                                ;   in Loop: Header=BB6_1 Depth=1
	ld	hl, (ix - 3)
	ld	hl, (hl)
	add	hl, bc
	or	a, a
	sbc	hl, bc
	jr	z, .LBB6_5
; %bb.3:                                ;   in Loop: Header=BB6_1 Depth=1
	ld	hl, (ix - 9)
	inc	hl
	ld	iy, (ix - 3)
	lea	iy, iy + 3
	ld	(ix - 3), iy
	ld	iy, (ix - 6)
	lea	iy, iy + 9
	ld	(ix - 6), iy
	push	bc
	pop	de
	push	hl
	pop	bc
	jr	.LBB6_1
	.local	.LBB6_4
.LBB6_4:
	ld	de, -1
	ex	de, hl
	jr	.LBB6_6
	.local	.LBB6_5
.LBB6_5:
	ld	hl, (ix + 9)
	ld	de, (ix - 6)
	push	de
	pop	iy
	ld	(iy - 3), hl
	ld	hl, (ix + 12)
	ld	(iy), hl
	or	a, a
	sbc	hl, hl
	ld	(iy + 3), hl
	ld	hl, (ix - 9)
	.local	.LBB6_6
.LBB6_6:                                ; %.loopexit
	ld	sp, ix
	pop	ix
	ret
	.local	.Lfunc_end6
.Lfunc_end6:
	.size	__ZN8Renderer23registerRenderingEntityEP8PositionP10Dimensions, .Lfunc_end6-__ZN8Renderer23registerRenderingEntityEP8PositionP10Dimensions
                                        ; -- End function
	.section	.text.__ZN8Renderer25unregisterRenderingEntityEi,"ax",@progbits
	.globl	__ZN8Renderer25unregisterRenderingEntityEi ; -- Begin function _ZN8Renderer25unregisterRenderingEntityEi
	.type	__ZN8Renderer25unregisterRenderingEntityEi,@function
__ZN8Renderer25unregisterRenderingEntityEi: ; @_ZN8Renderer25unregisterRenderingEntityEi
; %bb.0:
	call	__frameset0
	ld	bc, (ix + 9)
	ld	de, 16
	push	bc
	pop	hl
	or	a, a
	sbc	hl, de
	jr	c, .LBB7_2
; %bb.1:
	ld	de, 1
	jr	.LBB7_3
	.local	.LBB7_2
.LBB7_2:
	ld	iy, (ix + 6)
	ld	de, 0
	push	bc
	pop	hl
	ld	bc, 3
	call	__imulu
	push	hl
	pop	bc
	add	iy, bc
	ld	bc, 144
	add	iy, bc
	ld	(iy), de
	.local	.LBB7_3
.LBB7_3:
	ex	de, hl
	pop	ix
	ret
	.local	.Lfunc_end7
.Lfunc_end7:
	.size	__ZN8Renderer25unregisterRenderingEntityEi, .Lfunc_end7-__ZN8Renderer25unregisterRenderingEntityEi
                                        ; -- End function
	.section	.text.__ZN8Renderer23renderRenderingEntitiesEv,"ax",@progbits
	.globl	__ZN8Renderer23renderRenderingEntitiesEv ; -- Begin function _ZN8Renderer23renderRenderingEntitiesEv
	.type	__ZN8Renderer23renderRenderingEntitiesEv,@function
__ZN8Renderer23renderRenderingEntitiesEv: ; @_ZN8Renderer23renderRenderingEntitiesEv
; %bb.0:
	ld	hl, -18
	call	__frameset
	ld	hl, (ix + 6)
	ld	de, 0
	ld	(ix - 3), de
	ld	iy, -144
	ld	de, 144
	add	hl, de
	lea	de, iy + 0
	ld	(ix - 6), hl
	.local	.LBB8_1
.LBB8_1:                                ; =>This Inner Loop Header: Depth=1
	sbc	hl, hl
	adc	hl, de
	jr	z, .LBB8_5
; %bb.2:                                ;   in Loop: Header=BB8_1 Depth=1
	ld	hl, (ix - 6)
	ld	bc, (ix - 3)
	add	hl, bc
	ld	hl, (hl)
	add	hl, bc
	or	a, a
	sbc	hl, bc
	jr	z, .LBB8_4
; %bb.3:                                ;   in Loop: Header=BB8_1 Depth=1
	ld	iy, (ix - 6)
	add	iy, de
	ld	hl, (iy)
	ld	(ix - 15), hl
	ld	hl, (iy + 3)
	ld	(ix - 12), hl
	ld	hl, (iy + 6)
	ld	a, (hl)
	ld	l, a
	push	hl
	ld	(ix - 9), de
	call	_gfx_SetColor
	pop	hl
	ld	iy, (ix - 15)
	ld	hl, (iy)
	ld	(ix - 18), hl
	ld	de, (iy + 3)
	ld	iy, (ix - 12)
	ld	bc, (iy)
	ld	hl, (iy + 3)
	push	hl
	push	bc
	push	de
	ld	hl, (ix - 18)
	push	hl
	call	_gfx_FillRectangle
	ld	de, (ix - 9)
	pop	hl
	pop	hl
	pop	hl
	pop	hl
	.local	.LBB8_4
.LBB8_4:                                ;   in Loop: Header=BB8_1 Depth=1
	ld	iy, (ix - 3)
	ld	bc, 3
	add	iy, bc
	ex	de, hl
	ld	de, 9
	add	hl, de
	ex	de, hl
	ld	(ix - 3), iy
	jr	.LBB8_1
	.local	.LBB8_5
.LBB8_5:
	ld	sp, ix
	pop	ix
	ret
	.local	.Lfunc_end8
.Lfunc_end8:
	.size	__ZN8Renderer23renderRenderingEntitiesEv, .Lfunc_end8-__ZN8Renderer23renderRenderingEntitiesEv
                                        ; -- End function
	.section	.text.__ZN8Renderer16renderBackgroundEv,"ax",@progbits
	.globl	__ZN8Renderer16renderBackgroundEv ; -- Begin function _ZN8Renderer16renderBackgroundEv
	.type	__ZN8Renderer16renderBackgroundEv,@function
__ZN8Renderer16renderBackgroundEv:      ; @_ZN8Renderer16renderBackgroundEv
; %bb.0:
	call	__frameset0
	ld	(ix + 6), 0
	pop	ix
	jp	_gfx_FillScreen
	.local	.Lfunc_end9
.Lfunc_end9:
	.size	__ZN8Renderer16renderBackgroundEv, .Lfunc_end9-__ZN8Renderer16renderBackgroundEv
                                        ; -- End function
	.section	.bss._keymap,"aw",@nobits
	.balign	2
	.globl	_keymap
_keymap:
	.zero	10

	.globl	__ZN6KeypadC1Ev
	.type	__ZN6KeypadC1Ev,@function
.set __ZN6KeypadC1Ev, __ZN6KeypadC2Ev
	.globl	__ZN8RendererC1Ev
	.type	__ZN8RendererC1Ev,@function
.set __ZN8RendererC1Ev, __ZN8RendererC2Ev
	.globl	__ZN8RendererD1Ev
	.type	__ZN8RendererD1Ev,@function
.set __ZN8RendererD1Ev, __ZN8RendererD2Ev
	.ident	"clang version 19.1.0 (https://github.com/CE-Programming/llvm-project ef28e9c54cd1333a6091ab2ffbd315b465fc5090)"
	.ident	"clang version 19.1.0 (https://github.com/CE-Programming/llvm-project ef28e9c54cd1333a6091ab2ffbd315b465fc5090)"
	.ident	"clang version 19.1.0 (https://github.com/CE-Programming/llvm-project ef28e9c54cd1333a6091ab2ffbd315b465fc5090)"
	.section	".note.GNU-stack","",@progbits
	.extern	_llvm.memset.p0.i24
	.extern	_gfx_SetColor
	.extern	_llvm.eh.sjlj.functioncontext
	.extern	_gfx_End
	.extern	_llvm.eh.sjlj.callsite
	.extern	_llvm.eh.sjlj.setup.dispatch
	.extern	_gfx_FillRectangle
	.extern	_llvm.stacksave.p0
	.extern	_llvm.lifetime.end.p0
	.extern	_llvm.lifetime.start.p0
	.extern	_llvm.eh.sjlj.lsda
	.extern	__frameset0
	.extern	__Unwind_SjLj_Register
	.extern	_llvm.frameaddress.p0
	.extern	__Unwind_SjLj_Unregister
	.extern	_gfx_FillScreen
	.extern	_llvm.stackrestore.p0
	.extern	__frameset
	.extern	__imulu
	.extern	_gfx_Begin
	.extern	__Znwj
