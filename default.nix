{ lib, stdenv, pkg-config, SDL2 }:

stdenv.mkDerivation {
	pname = "dummy-window";
	version = "1";

	src = ./.;

	buildInputs = [ pkg-config SDL2 ];

	installPhase = ''
		runHook preInstall
		
		install -D -t $out/bin ./dummy-window

		runHook postInstall
	'';
}
