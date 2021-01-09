#include "simpleIP4.h"

#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
    try {


        //
        std::vector<SimpleIP4> ip_pool;
        // receive IP from text
         for(std::string line; std::getline(std::cin, line);)
         {
              ip_pool.push_back(ParseIP4(line));
         }
         // вариант 1 "в лоб"
//          //reverse lexicographically sort
//       std::sort(ip_pool.rbegin(),ip_pool.rend());
//        // print all IP
//            for(const auto& el : ip_pool)
//            {
//                std::cout << el << std::endl;
//            }
//          // ip = filter(1)
//          //
//            for(const auto& el : ip_pool)
//            {
//                if(el.GetByte1() == 1)
//                std::cout << el << std::endl;
//            }
//          // ip = filter(46, 70)
//            for(const auto& el : ip_pool)
//            {
//                if(el.GetByte1() == 46 && el.GetByte2() == 70)
//                std::cout << el << std::endl;
//            }
//            //  ip = filter_any(46)
//              for(const auto& el : ip_pool)
//              {
//                  if(el.GetByte1() == 46 || el.GetByte2() == 46 || el.GetByte3() == 46 || el.GetByte4() == 46 )
//                  std::cout << el << std::endl;
//              }
         //вариант 2
         //все IP выводим так же
         // пока выводим - проверяем IP на фильтры
         // для filter(1), filter(46, 70) запоминает начало и конец и есть ли такие IP вообще
         // для filter_any(46) запоминаем номера подходящих элкментов в вектор
         bool isFilter1=false, isFilter2=false;
          bool isFindStartFilter1=false, isFindStartFilter2=false;
          bool isFindEndFilter1=false, isFindEndFilter2=false;
         std::size_t RangeFilter1Begin=0, RangeFilter1End=0, RangeFilter2Begin=0, RangeFilter2End=0;
         std::vector<size_t> NumElementsFilter3;
         //reverse lexicographically sort
      std::sort(ip_pool.rbegin(),ip_pool.rend());
       // print all IP
           for(size_t i = 0; i < ip_pool.size(); ++i)
           {
               //print IP
               std::cout << ip_pool.at(i) << std::endl;
               //ip = filter(1)
               if(!isFindEndFilter1)
               {
                   if(ip_pool.at(i).GetByte1() == 1)
                   {
                       if(isFindStartFilter1)
                       {
                          RangeFilter1End = i;
                       }
                       else
                       {
                           //
                           RangeFilter1Begin = i;
                           isFindStartFilter1 = true;
                           isFilter1=true;
                       }
                   }
                   else
                   {
                       if(isFindStartFilter1)
                       {
                           isFindEndFilter1 = true;

                       }
                   }
               }
               //ip = filter(46, 70)
               if(!isFindEndFilter2)
               {
                   if(ip_pool.at(i).GetByte1() == 46 && ip_pool.at(i).GetByte2() == 70)
                   {
                       if(isFindStartFilter2)
                       {
                            RangeFilter2End = i;
                       }
                       else
                       {
                           //
                           RangeFilter2Begin = i;
                           isFindStartFilter2 = true;
                           isFilter2=true;
                       }
                   }
                   else
                   {
                       if(isFindStartFilter2)
                       {
                           isFindEndFilter2 = true;

                       }
                   }
               }
               //  ip = filter_any(46)
               if(ip_pool.at(i).GetByte1() == 46 || ip_pool.at(i).GetByte2() == 46 || ip_pool.at(i).GetByte3() == 46 || ip_pool.at(i).GetByte4() == 46 )
               {
                   NumElementsFilter3.push_back(i);
               }
           }
         // ip = filter(1) print
         //
           if(isFilter1)
          {
           for(size_t i = RangeFilter1Begin; i <= RangeFilter1End; ++i)
           {
               std::cout << ip_pool.at(i) << std::endl;
           }
           }
         // ip = filter(46, 70) print
           if(isFilter2)
          {
           for(size_t i = RangeFilter2Begin; i <= RangeFilter2End; ++i)
           {
               std::cout << ip_pool.at(i) << std::endl;
           }
           }
           //  ip = filter_any(46) print
             for(const auto& el :  NumElementsFilter3)
             {
               std::cout << ip_pool.at(el) << std::endl;
             }
 // вариант 3 используя алгоритмы и лямбды - ???
 // вариант 4  - ДЗ на лекции через ranges
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
      }

	return 0;
}
