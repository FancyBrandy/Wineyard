#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>

void handler(int signum,siginfo_t* p, void* nonused)
{
	
		printf("the signal is received!\n");
		printf("the number of worker delivered is %d\n", p->si_value.sival_int);

}
int main()
{
	pid_t pid,ppid;
	ppid=getpid();
	int pipefd[2];
	pipe(pipefd);
	char sz[200];// char array for reading from the pipe.	
	int limit=7;//define the limit of the number of workers
	char Brilliant_Land[50];
	char Sparkling_Ground[50];
	char Long_Plot[50];
	char Silky_Land[50];
	char Miller_Ground[50];
	char Red_Plot[50];
	strcpy(Brilliant_Land,"incision");
	strcpy(Sparkling_Ground,"spraying");
	strcpy(Long_Plot,"spring,opening");
	strcpy(Silky_Land,"hoe,work");
	strcpy(Miller_Ground,"incision");
	strcpy(Red_Plot,"spraying");

	pid_t first_child=fork();//creating the first child
	
	
	if(first_child==0)//the first child process
	{
		printf("child starts writing the messages to the parent process\n...........................\n");
		if(strcmp(Brilliant_Land,"incision")==0)
		{
			write(pipefd[1],"Brilliant_Land,incision  ",25);
		}
		else if(strcmp(Brilliant_Land,"spraying")==0)
		{
			write(pipefd[1],"Brilliant_Land, spraying",24);
		}
		else if(strcmp(Brilliant_Land,"spring,opening")==0)
		{
			write(pipefd[1],"Brilliant_Land, spring opening",31);
		}
		else if(strcmp(Brilliant_Land,"hoe,work")==0)
		{
			write(pipefd[1],"Brilliant_Land, hoe work",25);
		}
		
		
		
		if(strcmp(Sparkling_Ground,"incision")==0)
		{
			write(pipefd[1],"Sparkling Ground, incision",27 );
		}
		else if(strcmp(Sparkling_Ground,"spraying")==0)
		{
			write(pipefd[1],"Sparkling Ground,spraying  ",27);
		}
		else if(strcmp(Sparkling_Ground,"spring,opening")==0)
		{
			write(pipefd[1],"Sparkling_Ground, spring opening",27);
		}
		else if(strcmp(Sparkling_Ground,"hoe,work")==0)
		{
			write(pipefd[1],"Sparkling_Ground, hoe work",27);
		}
		
		
		
		if(strcmp(Long_Plot,"incision")==0)
		{
			write(pipefd[1],"Long_Plot, incision",27 );
		}
		else if(strcmp(Long_Plot,"spraying")==0)
		{
			write(pipefd[1],"Long_Plot, spraying",27);
		}
		else if(strcmp(Long_Plot,"spring,opening")==0)
		{
			write(pipefd[1],"Long_Plot, spring opening  ",27);
		}
		else if(strcmp(Long_Plot,"hoe,work")==0)
		{
			write(pipefd[1],"Long_Plot, hoe work",27);
		}
		
		
		
		if(strcmp(Silky_Land,"incision")==0)
		{
			write(pipefd[1],"Silky_Land, incision",27 );
		}
		else if(strcmp(Silky_Land,"spraying")==0)
		{
			write(pipefd[1],"Silky_Land, spraying",27);
		}
		else if(strcmp(Silky_Land,"spring,opening")==0)
		{
			write(pipefd[1],"Silky_Land, spring opening",27);
		}
		else if(strcmp(Silky_Land,"hoe,work")==0)
		{
			write(pipefd[1],"Silky_Land, hoe work  ",22);
		}
		
		
		
		if(strcmp(Miller_Ground,"incision")==0)
		{
			write(pipefd[1],"Miller_Ground, incision  ",25 );
		}
		else if(strcmp(Miller_Ground,"spraying")==0)
		{
			write(pipefd[1],"Miller_Ground, spraying",27);
		}
		else if(strcmp(Miller_Ground,"spring,opening")==0)
		{
			write(pipefd[1],"Miller_Ground, spring opening",27);
		}
		else if(strcmp(Miller_Ground,"hoe,work")==0)
		{
			write(pipefd[1],"Miller_Ground, hoe work",27);
		}
		
		
		if(strcmp(Red_Plot,"incision")==0)
		{
			write(pipefd[1],"Red_Plot, incision",27 );
		}
		else if(strcmp(Red_Plot,"spraying")==0)
		{
			write(pipefd[1],"Red_Plot, spraying  ",20);
		}
		else if(strcmp(Red_Plot,"spring,opening")==0)
		{
			write(pipefd[1],"Red_Plot, spring opening",27);
		}
		else if(strcmp(Red_Plot,"hoe,work")==0)
		{
			write(pipefd[1],"Red_Plot, hoe work",27);
		}
		close(pipefd[1]);// tell the parent that we are done writing.
		printf("the first child finish writing the message\n..............................................\n");
	}
	
	else if(first_child>0)//the parent process
	{
		int status;
		waitpid(first_child,&status,0);//waits for the first child to terminate.(getting the meesage from the first child)
		printf("the parent is reading the message now\n..................................................\n");
		
		read(pipefd[0],sz,200);
		printf("the kind of work that are urgently required on each part of the wine yard are: \n");
		printf("%s\n",sz);
		close(pipefd[0]);

		int p[2];
		pipe(p);//we build a new pipe for the new process communication
		char ch[1000];

		write(p[1],"Anna-----Briliant land, incision; ",34);
		write(p[1],"Charles-----Sparkling Ground, spraying; ",40);
		write(p[1],"Rachel-----Long Plot, spring opening; ",38);
		write(p[1],"Daniel-----Silky Land, hoe work; ",33 );
		write(p[1],"David-----Miller Ground, incision; ",35);//here we can also use scanf instead of writing directlu
		//reading from the pipe and send the message to the second child.
		close(p[1]);
		printf("parent process finish reading the message and starts sending the second child process command\n............................\n");
	pid_t second_child=fork();

	struct sigaction sa;
	sa.sa_sigaction=handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=SA_SIGINFO;
	sigaction(SIGINT,&sa,NULL);
	wait(NULL);
	
	if(second_child==0)//the second child process
		{
			sleep(3);
			printf("the second child starts reading\n");
			read(p[0],ch,1000);
			printf("the worker's names and their jobs are:\n");
			printf("%s\n",ch);
			printf("the second child finish reading\n");
			close(p[0]);
			int number=5;
			if(number<limit)
				printf("not enough workers, please enter more workers name:\n ");
			char other_worker[limit-number][10];
			for(int i=0;i<(limit-number);i++)
			{
				printf("please enter the %d's other worker's name:...............\n",(i+1));
				scanf("%s",&other_worker[i]);
			}	
			//printf("%d number of workers are delivered!\n",limit-number);
			union sigval s_value_ptr;
			s_value_ptr.sival_int=limit-number;
			sigqueue(ppid,SIGINT,s_value_ptr);
			printf("child process ended\n");

		}

	}
		
	
}
