#include "file.h"
#include <vector>
#include <iostream>

namespace problem_054 {
    struct card {
        int number;
        char suit;
    };
    enum hand {
        royalFlush = 1,
        straightFlush = 2,
        fourOfAKind = 3,
        fullHouse = 4,
        flush = 5,
        straight = 6,
        threeOfAKind = 7,
        twoPairs = 8,
        onePair = 9,
        nothing = 10
    };

    card getCard(std::string_view str, int start) {
        int nr = 0;
        if (str[start] >= '2' && str[start] <= '9') {
            nr = str[start] - '0';
        }
        else {
            switch (str[start]) {
                case 'T':
                    nr = 10;
                    break;
                case 'J':
                    nr = 11;
                    break;
                case 'Q':
                    nr = 12;
                    break;
                case 'K':
                    nr = 13;
                    break;
                case 'A':
                    nr = 14;
                    break;
            }
        }
        return {nr, str[start + 1]};
    }

    bool isRoyalFlush(const std::vector<card>& cards) {
        for (int i = 0; i < cards.size(); ++i) {
            if (cards[i].number != i + 10) {
                return false;
            }
            if (i > 0 && cards[i].suit != cards[i - 1].suit) {
                return false;
            }
        }
        return true;
    }

    bool isStraightFlush(const std::vector<card>& cards) {
        for (int i = 1; i < cards.size(); ++i) {
            if (cards[i].number != cards[i - 1].number + 1) {
                return false;
            }
            if (cards[i].suit != cards[i - 1].suit) {
                return false;
            }
        }
        return true;
    }

    bool isFourOfAKind(const std::vector<card>& cards) {
        return ((cards[0].number == cards[3].number) || (cards[1].number == cards[4].number));
    }

    bool isFullHouse(const std::vector<card>& cards) {
        return ((cards[0].number == cards[1].number && cards[2].number == cards[4].number) ||
                (cards[0].number == cards[2].number && cards[3].number == cards[4].number));
    }

    bool isFlush(const std::vector<card>& cards) {
        for (int i = 1; i < cards.size(); ++i) {
            if (cards[i - 1].suit != cards[i].suit) {
                return false;
            }
        }
        return true;
    }

    bool isStraight(const std::vector<card>& cards) {
        for (int i = 1; i < cards.size(); ++i) {
            if (cards[i - 1].number + 1 != cards[i].number) {
                return false;
            }
        }
        return true;
    }

    bool isThreeOfAKind(const std::vector<card>& cards) {
        return (cards[0].number == cards[2].number || cards[1].number == cards[3].number || cards[2].number == cards[4].number);
    }

    bool isTwoPairs(const std::vector<card>& cards) {
        int pairs = 0;
        for (int i = 1; i < cards.size(); ++i) {
            pairs += (cards[i].number == cards[i - 1].number);
        }
        return (pairs == 2);
    }

    bool isOnePair(const std::vector<card>& cards) {
        int pairs = 0;
        for (int i = 1; i < cards.size(); ++i) {
            pairs += (cards[i].number == cards[i - 1].number);
        }
        return (pairs == 1);
    }

    hand getHand(const std::vector<card>& cards) {
        std::vector<std::pair<bool (*)(const std::vector<card>&), hand>> compare {{isRoyalFlush, hand::royalFlush},
                                                                                  {isStraightFlush, hand::straightFlush},
                                                                                  {isFourOfAKind, hand::fourOfAKind},
                                                                                  {isFullHouse, hand::fullHouse},
                                                                                  {isFlush, hand::flush},
                                                                                  {isStraight, hand::straight},
                                                                                  {isThreeOfAKind, hand::threeOfAKind},
                                                                                  {isTwoPairs, hand::twoPairs},
                                                                                  {isOnePair, hand::onePair}};
        for (const auto& c : compare) {
            if (c.first(cards)) {
                return c.second;
            }
        }
        return hand::nothing;
    }

    bool player1HasHighestCard(const std::vector<card>& player1, const std::vector<card>& player2) {
        int i = player1.size() - 1;
        while (i >= 0) {
            if (player1[i].number > player2[i].number) {
                return true;
            }
            if (player1[i].number < player2[i].number) {
                return false;
            }
            i++;
        }
        return false;
    }

    bool player1HasHigherPair(const std::vector<card>& player1, const std::vector<card>& player2) {
        int pair1 = 0, pair2 = 0;
        for (int i = 1; i < player1.size(); ++i) {
            if (player1[i].number == player1[i - 1].number) {
                pair1 = player1[i].number;
            }
            if (player2[i].number == player2[i - 1].number) {
                pair2 = player2[i].number;
            }
        }
        if (pair1 != pair2) {
            return (pair1 > pair2);
        }
        return player1HasHighestCard(player1, player2);
    }

    bool player1HasHigher2Pairs(const std::vector<card>& player1, const std::vector<card>& player2) {
        std::vector<int> pair1, pair2;
        for (int i = 1; i < player1.size(); ++i) {
            if (player1[i].number == player1[i - 1].number) {
                pair1.push_back(player1[i].number);
            }
            if (player2[i].number == player2[i - 1].number) {
                pair2.push_back(player2[i].number);
            }
        }
        for (int i = 1; i >= 0; --i) {
            if (pair1[i] != pair2[i]) {
                return (pair1[i] > pair2[i]);
            }
        }
        return player1HasHighestCard(player1, player2);
    }

    bool player1HasHigherThree(const std::vector<card>& player1, const std::vector<card>& player2) {
        int three1 = 0, three2 = 0;
        for (int i = 2; i < player1.size(); ++i) {
            if (player1[i].number == player1[i - 2].number) {
                three1 = player1[i].number;
            }
            if (player2[i].number == player2[i - 2].number) {
                three2 = player2[i].number;
            }
        }
        if (three1 != three2) {
            return (three1 > three2);
        }
        return player1HasHighestCard(player1, player2);
    }

    bool player1HasHigherFour(const std::vector<card>& player1, const std::vector<card>& player2) {
        int four1 = 0, four2 = 0;
        for (int i = 3; i < player1.size(); ++i) {
            if (player1[i].number == player1[i - 3].number) {
                four1 = player1[i].number;
            }
            if (player2[i].number == player2[i - 3].number) {
                four2 = player2[i].number;
            }
        }
        if (four1 != four2) {
            return (four1 > four2);
        }
        return player1HasHighestCard(player1, player2);
    }

    bool player1Wins(const std::vector<card>& player1, const std::vector<card>& player2) {
        std::vector<std::pair<bool (*)(const std::vector<card>&, const std::vector<card>&), hand>> compare {{player1HasHighestCard, hand::nothing},
                                                                                                            {player1HasHigherPair, hand::onePair},
                                                                                                            {player1HasHigher2Pairs, hand::twoPairs},
                                                                                                            {player1HasHigherThree, hand::threeOfAKind},
                                                                                                            {player1HasHighestCard, hand::straight},
                                                                                                            {player1HasHighestCard, hand::flush},
                                                                                                            {player1HasHigherThree, hand::fullHouse},
                                                                                                            {player1HasHigherFour, hand::fourOfAKind},
                                                                                                            {player1HasHighestCard, hand::straightFlush},
                                                                                                            {player1HasHighestCard, hand::royalFlush}};
        hand handPlayer1 = getHand(player1);
        hand handPlayer2 = getHand(player2);
        if (handPlayer1 != handPlayer2) {
            return (handPlayer1 < handPlayer2);
        }
        for (const auto& c : compare) {
            if (handPlayer1 == c.second) {
                return c.first(player1, player2);
            }
        }
        return false;
    }

    int solve() {
        std::vector<std::string> lines = file::readFileAsArrayOfString("../problems/problem_054/input/input.in");

        int wins = 0;
        for (const auto& line : lines) {
            std::vector<card> player1;
            std::vector<card> player2;
            int middle = line.size() / 2 + 1;
            for (int i = 0; i < middle; ++i) {
                player1.push_back(getCard(line, i));
                i = i + 2;
            }
            for (int i = middle; i < line.size(); ++i) {
                player2.push_back(getCard(line, i));
                i = i + 2;
            }
            std::sort(player1.begin(), player1.end(), [](const auto& a, const auto& b) {
                return a.number < b.number;
            });

            std::sort(player2.begin(), player2.end(), [](const auto& a, const auto& b) {
                return a.number < b.number;
            });

            wins += player1Wins(player1, player2);
        }

        return wins;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_054::solve() << std::endl;

    return 0;
}
#endif
