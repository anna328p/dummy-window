{ pkgs ? import <nixpkgs> { } }:

(pkgs.callPackage ./default.nix { }).overrideAttrs (oa: {
	nativeBuildInputs = with pkgs; [ valgrind gdb ];
})
