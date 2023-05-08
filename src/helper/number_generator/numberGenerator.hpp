/*
** EPITECH PROJECT, 2023
** RPG3
** File description:
** numberGenerator
*/

#ifndef NUMBERGENERATOR_HPP_
    #define NUMBERGENERATOR_HPP_

    namespace bya {
        class nbgen {
            public:
                static int between(int a, int b);
                static float between(float a, float b);
                static bool boolean();
            private:
                nbgen();
        };
    }

#endif /* !NUMBERGENERATOR_HPP_ */
