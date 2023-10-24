#pragma once
#include <algorithm>
#include <type_traits>
#include <iterator>


/// Ну, все solution собрал, давай сначала по ошибкам.
/// Ну во-первых Падает на Compare(first, curretFirst). А знаешь почему? Потому что Compare это тип, а надо позвать от самого параметра...
/// Во вторых там где enable_if надо еще имя типу дать, что-то вроде typename T = std::enable_if<std::is_arithmetic_v<RandomAccessIterator>>::type>
/// И все, оно компилится. А теперь разбор полетов:
/// 1. Убирай swap, он медленный, когда начнется move-семантика ты еще успеешь наиграться с его правильной реализацей.
/// 2. Какая-то херабора с алгоритмом... Падает в рантайме, где-то с памятью ошибка, попробуй подебажить и понять в чем ошибка.
/// 3. Хочу дефолтный компаратор, std::less например.
/// 4. SFINAE у тебя наверное тестовый, потому что хочется проверку на то, что итератор является Random Access, а у тебя проверка на то, что он поддерживает арифметику 0_o


//Вторая итерация:
// Алгоритм рабочий, SFINAE норм. Теперь по замечаниям:
// 1. Параметр Compare в шаблоне должен быть по умолчанию такой: class Compare = std::less<>.
// 2. Сделай декомпозицию. Сделай новую функцию, назови ее quickSort например. Она будет с enable_if, параметрами по умолчанию и тд...
// А внутри ее тела будет только вызов функции sort. В самой реализации sort убираем enable_if и тд... Остаются только шаблоны и тело.
// 3. Ну и про тесты. Мне тесты конечно не принципиальны, но у тебя они какие-то жиденькие... Добавь пару тестов на double, статические массивы что ли :)


namespace sortFunction
{
	template <class RandomAccessIterator, typename Compare>
    void sort(RandomAccessIterator first, RandomAccessIterator last, const Compare& comp) {
        if (first != last) {
            RandomAccessIterator left = first;
            RandomAccessIterator right = last;
            RandomAccessIterator pivot = left++;

            while (left != right) {
                if (comp(*left, *pivot)) {
                    ++left;
                }
                else {
                    while ((left != --right) && comp(*pivot, *right));
                    std::iter_swap(left, right);
                }
            }
            --left;
            std::iter_swap(first, left);
            sortFunction::sort(first, left, comp);
            sortFunction::sort(right, last, comp);
        }
    }

    template <class RandomAccessIterator, typename Compare = std::less<>, typename T = std::enable_if<std::is_same<typename std::iterator_traits<RandomAccessIterator>::iterator_category, std::random_access_iterator_tag>::value>>
    void quickSort(RandomAccessIterator first, RandomAccessIterator last, const Compare& comp = Compare{}) {
        sortFunction::sort(first, last, comp);
    };
}


