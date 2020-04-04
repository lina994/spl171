# spl171
Systems Programming 2017 Ben-Gurion University.

## Assignment 1 - Reviiyot

C++

### Rules:
1. Each player gets 7 cards from the shuffled deck of cards, starting with Player1.
2. A player that received 4 cards of a single value discards the set from his hand before the first play of the first player.
3. At his/her turn, the player, according to his/her strategy, asks another player for a card of a specific value (2,3,...,N, Jack, Queen, King and Ace). The asking player can ask only for values that he/she holds at least one card of that same value.
4. If the asked player holds K(>0) cards of that value he/she has to give all of his/her cards of that value to the asking player and draw K new cards from the top of the deck. 
5. If the asked player doesn't have any card of that value the asking player picks up one card from the top of the deck.
6. A player draws card(s) from the deck ONLY if his/her hand is not empty.
7. If the deck of cards is empty the game continues without drawing new cards.
8. Any player that has all 4 cards of a single value discards the set from his hand.
9. The first player(s) that gets rid of his/her cards wins and the game ends. Be aware that two players can win the game simultaneously.

### Compile and run:
```
make clean
make
./bin/reviiot ./config1.txt
```
