﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TextRPG
{
    public class Store
    {
        public Item[] item;

        public Store()
        {
            item = new Item[100];
            item[0] = new Item("수련자 갑옷", false, false, "방어력", 5, "수련에 도움을 주는 갑옷입니다.", 1000);
            item[1] = new Item("무쇠 갑옷", true, true, "방어력", 9, "무쇠로 만들어져 튼튼한 갑옷입니다.", 2000);
            item[2] = new Item("전설의 갑옷", false, false, "방어력", 15, "스파르타의 전사들이 사용했다는 전설의 갑옷입니다.", 3500);
            item[3] = new Item("낡은 도끼", false, true, "공격력", 2, "쉽게 볼 수 있는 낡은 검 입니다.", 600);
            item[4] = new Item("청동 도끼", false, false, "공격력", 5, "어디선가 사용됐던거 같은 도끼입니다.", 1500);
            item[5] = new Item("전설의 창", true, true, "공격력", 7, "스파르타의 전사들이 사용했다는 전설의 창입니다.", 2000);
            item[6] = new Item("두꺼운 책", false, false, "공격력", 1, "모서리로 맞으면 꽤 아플거 같은 책입니다.", 500);
        }

    }

}