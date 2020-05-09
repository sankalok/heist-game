# heist-game
Text based approach to a Heist Game for ENGG1340 Group Project
Group No.: 220 (ENGG1340)

Participants:
Name—Raghav Agarwal; UID—3035720697; Major—BEng Year 1
Name—Sankalok Sen; UID—3035667869; Major—BEng Year 1


The game is based on a heist scenario. The player has to choose the most viable option
	according to him and it would affect the outcome of the game. The game should
	be played to maximise the stay inside the mint and loot as much money as possible
Basic Rules:-
	1)The players are instructed to not press the buttons when it is mentioned in the Game.
	2)The players should not press the escape option through the tunnel unless the tunnel is ready
	3)Players are awarded 10000$ for each surviving team member.
	4)Players are awarded 1000$ for each day they've spent in the mint
	5)The forex money option generates money between(10000-100000) dollars.
	6)The print money decreses after 5 days interval by 10000$ until 50000$ is reached.
	7)If heist members required to perform specific tasks are sacrificed you should not click on those tasks.
	8)You can spend money to lower risk of getting caught.
	9)The game ends when either the player leaves or the risk level reaches 100.
	10)Optimize your moves to gain the maximum money and be the heist king!!
	
List of features:-
        1)Generation of random game sets or events- The first options provided to the player in a scenario are random and the critical scenario which the player faces is random, Also the forex amount available is generated randomly.
	2)data structures for storing game status- Linked list has been used to store informaton of each day, and arrays have been used to store scenarios and relevant options.
	3)Dynamic Memory Management- The linked list used for storing each day is a dynamic data structure(day) along with a dynamic string used to identify the members which are alive and print them as options for sacrifice(memb).
	4)File input/output - This has been used to store the name of the top ten players and create a leaderboard.
	5)Program code in multiple files - Multiple files such as bank_heist, highscores, mergenameandscores have been used. bank_heist contains the code for the game and for the user to input their name. The highscores has code for creating the leader board file. and the mergenameandscore file is for merging the username with its corresponding score.
