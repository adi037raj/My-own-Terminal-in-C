all:
	gcc problem.c -lreadline evaluate_for_mv.c evaluate_for_cp.c evaluate_for_grep.c 
	
execute:
	./a.out
