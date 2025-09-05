{ pkgs, ... }:

{
  # https://devenv.sh/packages/
  packages = with pkgs; [ git nixfmt-classic rubocop ];

  # https://devenv.sh/languages/
  languages.c.enable = true;

  # https://devenv.sh/tasks/
  tasks = {
    "lint:run".exec = ''
      git ls-files --cached --others --exclude-standard '*.c' '*.h' | xargs clang-format -i
      nixfmt devenv.nix
      rubocop -A kAFL/Vagrantfile'';
  };

  # https://devenv.sh/git-hooks/
  git-hooks.excludes = [ ".devenv" ];
  git-hooks.hooks = {
    clang-format.enable = true;
    mdformat.enable = true;
    nixfmt-classic.enable = true;
    trim-trailing-whitespace.enable = true;
  };

  # See full reference at https://devenv.sh/reference/options/
}
