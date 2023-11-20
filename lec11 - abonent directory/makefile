headers := abonentstruct.h main_functions.h
funcs := FAbonentDisplayInfo.c FAbonentList.c FPrintMenu.c FAbonentSearch.c FAbonentAdd.c FAbonentDelete.c
main := Main.c
all := $(headers) $(funcs) $(main)
bin := abonentdir.exe

$(bin): $(all)
		gcc $(all) -o $(bin)