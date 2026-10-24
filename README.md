# simple-highLow
-------------------------------
A game where you try to guess a randomly generated between 1 and 100.

-------------------------------

The code can consists of two files - random.h and highLow.cpp 

The random.h file utilizes the [Mersenne Twister PRNG](https://en.wikipedia.org/wiki/Mersenne_Twister) (The sequence repeats after 624 numbers but as this is an trivial game oh high-low, this limitation shouldn't hamper the play(unless you are a try hard and write down all 624 generated number )) included in the random library.

```
    inline std::mt19937 generate(){

        std::random_device rd{};

        std::seed_seq ss{static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),rd(),rd(),rd(),rd(),rd(),rd(),rd()};

        return std::mt19937{ss};
    }

    inline std::mt19937 mt{generate()};
```

I have used the steady_clock from the chrono library and 7 different random values generated from [std::random_device](https://en.cppreference.com/cpp/numeric/random/random_device) to initialize the seed.

-------------------------------

