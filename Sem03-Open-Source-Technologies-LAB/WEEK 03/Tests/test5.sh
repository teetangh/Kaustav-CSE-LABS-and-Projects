case $1 in 
*.c)
cc $1
;;
*.h|*.sh)
#do nothing
;;
esac
