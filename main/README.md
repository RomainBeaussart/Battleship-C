#Client
le client sur chaque pc

#Server
Sera lancer sur la machine du joueur qui heberge la partie

#Game Loop

while(no_winner) 
    playTurn()

___playTurn():
    Player1 attacks
    Player2 receiveTheAttack
    Player1 updateMarkBoard
    Win ?
    ___
    Player2 attacks
    Player1 receiveTheAttack
    Player2 updateMarkBoard
    Win ?
    ___
