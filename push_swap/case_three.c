#include "push_swap.h"

void		r_case_three(int *stack, int n, int ab)
{
	int		top;
	int		mid;
	int		bot;

	top = stack[0];
	bot	= stack[n - 1];
	if (n == 2)
	{
		if (top < bot)
			sab(stack, n, ab);
	}
	else
	{
		mid = stack[1];
		if (top > mid && top < bot)
			rrab(stack, n , ab);
		else if (top > mid && top > bot && mid < bot)
		{
			rrab(stack, n, ab);
			sab(stack, n, ab);
		}
		else if (top < mid && mid > bot && top < bot)
			rab(stack, n, ab);
		else if (top < mid && mid > bot && top > bot)
			sab(stack, n , ab);
		else if (top > mid && top > bot && mid > bot)
		{
			sab(stack, n, ab);
			rrab(stack, n, ab);
		}
	}
}

void		case_three(int *stack, int n, int ab)
{
	int		top;
	int		mid;
	int		bot;

	top = stack[0];
	bot = stack[n - 1];
	if (n == 2)
	{
		if (top > bot)
			sab(stack, n, ab);
	}
	else
	{
		mid = stack[1];
		if (top > mid && top < bot)
			sab(stack, n, ab);
		else if (top > mid && top > bot && mid > bot)
		{
			sab(stack, n, ab);
			rrab(stack, n, ab);
		}
		else if (top > mid && top > bot && mid < bot)
			rab(stack, n, ab);
		else if (top < mid && mid > bot && top < bot)
		{
			sab(stack, n, ab);
			rab(stack, n, ab);
		}
		else if (top < mid && mid > bot && top > bot)
			rrab(stack, n, ab);
	}
}