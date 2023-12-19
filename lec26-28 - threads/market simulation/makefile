headers := MarketSimulationLib.h
funcs := LoaderFunc.c CustomerFunc.c
main := Main.c
all := $(headers) $(funcs) $(main)
bin := MarketSimulation.exe

$(bin): $(all)
		gcc $(all) -o $(bin) -g	