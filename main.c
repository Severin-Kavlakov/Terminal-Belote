/* БЕЛОТ https://belot.bg/belot/rules/


ASCII art styled belote game running in the terminal. Written in C.


РАЗДАВАНЕ
    CCW,
    първо по 3 карти
    после още 2

НАДДАВАНЕ
    if we don't have good cards for a move :
        say pass
    else :
        say the move
    if trump/no trump/all trump said AND 3 passes after that :
        play on the rule
    if 4 passes in a row :
        restart game

    ред по сила при наддаване: спатия, каро, купа, пика,           без коз, всичко коз
        на човешки език:     детелина, ромб, сърце, черно сърце

РАЗИГРАВАНЕ
    find legal cards to play
    choose best based on predictions/strategies

ТОЧКУВАНЕ
    define different points of cards based on game played
    count points for both teams

ARRANGEMENT:
            bot 2
bot 3                   bot 1
            PLAYER

TEAMS: PLAYER + bot 2
       bot 1  + bot 4

the functions are the same for all bots ; we call them for each bot every move
separate functions/if statements inside the bot functions FOR THE PLAYER

*************************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum { // 0    1    2   3   4   5   6   7-strongest
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
} rank;

typedef enum { // 0    1    2   3-strongest
    SPADES,
    DIAMONDS,
    HEARTS,
    CLUBS
} suit;

typedef struct { // card = 2 ints in struct
    suit suit;
    rank rank;
} card;

typedef struct { // hand = array of cards
    card cards[8];
} hand;

//DISTRIBUTING
void init_deck(card deck[32]) {
    uint8_t initDeckIndex = 0;
    for (suit suit = SPADES; suit <= CLUBS; suit++) {  // suit from 0 to 4
        for (rank rank = SEVEN; rank <= ACE; rank++) { // rank from 0 to 7
            deck[initDeckIndex++] = (card){suit, rank};//typecast
        }
    }
}

void shuffle_cards(card deck[32]) {   // Fisher-Yates shuffle - all possible shuffles = equally likely
    for (uint8_t index = 0; index < 32; index++) { // 31 = max index in arr of 32
        uint8_t randomIndex = rand() % (index+1); // random index = from 0 to index

        card tempCardBuffer = deck[index];  // card        -> copied to   -> temp
        deck[index] = deck[randomIndex];    // card        -> replaced by -> random card
        deck[randomIndex] = tempCardBuffer; // random card -> replaced by -> card        //previously in temp
    }
}

void distribute_cards(card deck[32], hand hands[4]) {
    for (uint8_t i; i <= 3; i++) { // 4* ( 3* give card from arr to player i)

    }
    for (uint8_t i; i <= 2; i++) { // 4* (player i (2* give card from arr))

    }
}


//BIDDING
typedef enum { // 0 to 6 ; 0 is the weakest
    BID_PASS,
    BID_DIAMONDS,
    BID_HEARTS,
    BID_CLUBS,
    BID_NO_TRUMP,
    BID_ALL_TRUMP
} bid;

typedef struct {
    bid currentBid;
    bid lastBid;
    uint8_t lastBidder;
    uint8_t currentBidder;
    uint8_t passesInRow;
} biddingGamestate;

void declare_bid_player() {
    char test[20];
    scanf("%s", test);
    printf("%s\n", test);
}
void declare_bid_bot(const hand botHand) {

}


//PLAYING
typedef struct {
    bid playingBid;
    uint8_t lastTrickWinner;

    //...

} playingGamestate;

void make_a_move_bot(hand botHand) {

}
void make_a_move_player(hand playerHand) {

}


//SCORING                      7  8  9   10  J   Q  K   A
uint8_t pointsNotATrump[8] = { 0, 0, 0,  10, 2,  3, 4, 11 };
uint8_t pointsIsATrump[8]  = { 0, 0, 14, 10, 20, 3, 4, 11 };

hand winnedHands_player[8], winnedHands_bot1[8], winnedHands_bot2[8], winnedHands_bot3[8];
uint16_t points_player_bot2_Team, points_bot1_bot2_Team; // points for both teams

void count_points_from_a_taken_hand(bid playingBid, hand takenHand) { //will be ran with a for loop for all taken hands, for all players


}




int main() {
    //DISTRIBUTING
    card deck[32];
    hand allHands[4];

    init_deck(deck);
    printf("%d\n", deck);

    shuffle_cards(deck);
    printf("%d\n", deck);


    declare_bid_player();


    //BIDDING
    biddingGamestate biddingGamestate;

    //PLAYING
    playingGamestate playingGamestate;



    //SCORING


    return 0;
}
