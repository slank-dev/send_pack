
/*
 *Copyright (C) 2014-2015 Hiroki Shirokura <mail: slank.dev@gmail.com>
 *
 *TLexScan is free software: you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as published by
 *the Free Software Foundation, either version 3 of the License, or
 *(at your option) any later version.
 *
 *TLexScan is distributed in the hope that it will be useful,
 *
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.
 *
 *You should have received a copy of the GNU General Public License
 *along with this program.  
 *If not, see <http://slankdev.wordpress.com>.
 *slank (Hiroki Shirokura) <mail: slank.dev@gmail.com>
 *
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <unistd.h>
#include <sys/time.h>


#include <getopt.h>

#include "scanLan.h"	// for class TLexOps
#include "util.h"
#include "myclass.h"
#include "debug.h"


void parse_option(int argc, char** argv){
	
}


void MonitorLan(TLexOps opt){
	printf("monitoring lan!!\n");
	return;
}


int main(int argc, char** argv){
	int opt;
	struct timeval s, e;
	clock_t startTime, endTime;
	TLexOps conf;
	


	gettimeofday(&s, NULL);





	struct option long_options[] = {
		{"version", no_argument, 0, 0},
		{"help", no_argument, 0, 0},
		{"monitor", no_argument, 0, 0}
	};
	int opt_index;


	



	while((opt=getopt_long(argc,argv, "hvi:c:t:p:s:f:", long_options, &opt_index)) != -1){
		switch(opt){
			case 0:
				if(strcmp(long_options[opt_index].name, "version") == 0){
					printf("--version version()\n");
					version();
					break;
				}
				else if(strcmp(long_options[opt_index].name, "help") == 0){
					printf("--help help()\n");
					usage(argc,argv);
					break;
				}
				else if(strcmp(long_options[opt_index].name, "monitor") == 0){
					printf("--monitor monitoring mode!!!!!\n");
					MonitorLan(conf);
					break;
				}



			case 'h':
				printf("-h usage\n");
				usage(argc, argv);
				return 1;
				break;
			case 'v':
				printf("-v version()\n");
				version();
				return 1;
				break;
			case 'p':
				printf("-p print log\n");
				sortLog(optarg);		
				printLog(optarg);
				return 1;
				break;
			case 's':
				printf("-s sort log\n");
				sortLog(optarg);
				return 1;
				break;
			case 'i':
				printf("-i set interface\n");
				strncpy(conf.ifname, optarg, sizeof(conf.ifname));
				break;
			case 'c':
				printf("-c set loopcount\n");
				conf.scanLoopCount = atoi(optarg);
				break;
			case 't':
				printf("-t set timeout\n");
				conf.timeout = atoi(optarg);
				break;
			case 'f':
				printf("-f select logfile\n");
				strcpy(conf.logname, optarg);
				break;
		}
	}





	
	printf("\n");
	printf("Starting TLex 0.10 \n");
	conf.showConfig();
	//printf("\n");

	scanLan(conf);
	gettimeofday(&e, NULL);

	startTime = s.tv_sec + (double)(s.tv_usec * 1e-6);
	endTime = e.tv_sec + (double)(e.tv_usec * 1e-6);

	printf("\n");
	printf("TLex done: scan finished in ");
	printf("%lu.%lu sec\n",
			(long)e.tv_sec-s.tv_sec, (long)e.tv_usec-s.tv_usec);

}



