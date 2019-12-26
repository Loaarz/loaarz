#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

alias ls='ls --color=always'
PS1='\e[36m\u@\e[35m\h: \e[32m\W\e[0m\$ '

PATH="$HOME/bin/scripts:$PATH"
export PATH
