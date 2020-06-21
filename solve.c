/* author: Jonathan Liao
   CS 305 HW 4
   solve.c -- code to solve maze
*/

#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "stack.h"
#include "queue.h"

int solve_bfs(maze * the_maze) {

Queue q = initQueue();
enqueue(q, the_maze->entry);

  while(q != NULL) {
     coord to_explore = dequeue(q);
	if(to_explore.row == the_maze->exit.row && to_explore.col == the_maze->exit.col) { //found exit case
	   print_maze(the_maze); 
	   return 1;
	} 
	else { //exit not found yet; look for adjacent routes
	   the_maze->data[to_explore.row][to_explore.col] = 'o'; //mark that this part is explored
	   if(the_maze->data[to_explore.row - 1][to_explore.col] == ' ' && (to_explore.row - 1) >= 0 ) {
		enqueue(q, *make_coord(to_explore.row - 1, to_explore.col) );
	   }
	   if(the_maze->data[to_explore.row][to_explore.col + 1] == ' ' && (to_explore.col + 1) < the_maze->width ) {
		enqueue(q, *make_coord(to_explore.row, to_explore.col + 1) );
	   }
	   if(the_maze->data[to_explore.row + 1][to_explore.col] == ' ' && (to_explore.row) < the_maze->height ) {
		enqueue(q, *make_coord(to_explore.row + 1, to_explore.col) );
	   }
	   if(the_maze->data[to_explore.row][to_explore.col - 1] == ' ' && (to_explore.col - 1) >= 0 ) {
		enqueue(q, *make_coord(to_explore.row, to_explore.col - 1) );
	   }
	}
  }
  //expeled from while loop. Means queue is empty now
  print_maze(the_maze);
  free(q);
  return 0;

}

int solve_dfs(maze * the_maze) {

Stack s = initStack();
push(s, the_maze->entry);

  while(s != NULL) {
     coord to_explore = pop(s);
	if(to_explore.row == the_maze->exit.row && to_explore.col == the_maze->exit.col) { //found exit case
	   print_maze(the_maze); 
	   return 1;
	} 
	else { //exit not found yet; look for adjacent routes
	   the_maze->data[to_explore.row][to_explore.col] = 'o'; //mark that this part is explored
	   if(the_maze->data[to_explore.row - 1][to_explore.col] == ' ' && (to_explore.row - 1) >= 0 ) {
		push(s, *make_coord(to_explore.row - 1, to_explore.col) );
	   }
	   if(the_maze->data[to_explore.row][to_explore.col + 1] == ' ' && (to_explore.col + 1) < the_maze->width ) {
		push(s, *make_coord(to_explore.row, to_explore.col + 1) );
	   }
	   if(the_maze->data[to_explore.row + 1][to_explore.col] == ' ' && (to_explore.row) < the_maze->height ) {
		push(s, *make_coord(to_explore.row + 1, to_explore.col) );
	   }
	   if(the_maze->data[to_explore.row][to_explore.col - 1] == ' ' && (to_explore.col - 1) >= 0 ) {
		push(s, *make_coord(to_explore.row, to_explore.col - 1) );
	   }
	
	}	
  } 
  //expeled from while loop. Means stack is empty now
  print_maze(the_maze);
  free(s);
  return 0;
}

void print_maze(maze * the_maze) {

the_maze->data[the_maze->entry.row][the_maze->entry.col] = 'S';
the_maze->data[the_maze->exit.row][the_maze->exit.col] = 'F';
 
int i;
int j;

  for(i = 0; i < the_maze->height; i++) {
    for(j = 0; j < the_maze->width; j++) {
	printf("%c", the_maze->data[i][j]);
    }
	printf("\n"); //for some strange reason, the newline from the_maze->data won't print. Had to add this line
  }
return;
}

coord * make_coord(int r, int c) {

coord * new_coord = (coord *) malloc(sizeof(coord));
new_coord->row = r;
new_coord->col = c;

return new_coord;
}

void print_coord(coord c) {

printf("(%d),(%d)\n", c.row, c.col);
return;
}
