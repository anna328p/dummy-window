{
	inputs = {
		nixpkgs.url = github:nixos/nixpkgs;
		flake-utils.url = github:numtide/flake-utils;
	};

	outputs = { self
		, nixpkgs
		, flake-utils
	}: flake-utils.lib.eachDefaultSystem (system: let
		pkgs = import nixpkgs { inherit system; };
		
		pkg = pkgs.callPackage ./default.nix { };
		shell = import ./shell.nix { inherit pkgs; };
	in {
		packages.dummy-window = pkg;
		packages.default = pkg;

		devShells.dummy-window = shell;
		devShells.default = shell;
	});
}
