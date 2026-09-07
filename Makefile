#Makefile
a.out:std_add.o std_delall.o std_del.o std_main.o std_save.o std_show.o std_sort.o std_mod.o std_reverse.o
  cc std_add.o std_delall.o std_del.o std_main.o std_save.o std_show.o std_sort.o std_mod.c std_reverse.o  -o a.out
std_add.o: std_add.c
  cc -c std_add.c
std_delall.o: std_delall.c
  cc -c std_delall.c      
std_del.o: std_del.c
  cc -c std_del.c
std_main.o: std_main.c
  cc -c std_main.c
std_save.o: std_save.c
  cc -c std_save.c
std_show.o: std_show.c
  cc -c std_show.c
std_sort.o: std_sort.c
  cc -c std_sort.c
std_mod.o: std_mod.c
  cc -c std_mod.c
std_reverse.o: std_reverse.c
  cc -c std_reverse.c
clear:
  @echo "clening up...."
  @rm -vr *.o
 
                        
