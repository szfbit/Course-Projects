        var dayArr = new Array(31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31);
        var monArr=new Array("January","February","March","April","May","June","July","August",
            "September", "October", "November", "December");
        function yearClick()
        {
            var yearSel = document.getElementById('year');
            if (yearSel.options.length == 1) 
            {
                yearSel.options.remove(0);
                for (var i = 1990; i <= 2014; i++) 
                {
                    var opt = document.createElement("option");
                    opt.value = i;
                    opt.text = i;
                    yearSel.options.add(opt);
                }
            }
        }

        function yearChange()
        {
            if (document.getElementById('month').options.length != 1)
                getMonths();
            if (document.getElementById('day').options.length != 1)
                getDays();
        }

        function monthClick()
        {
            if (document.getElementById('year').options.length == 1)
            {
                return;
            }
            if (document.getElementById('month').options.length == 1) 
            {
                document.getElementById('month').options.remove(0);
                getMonths();
            }
        }

        function monthChange()
        {
            if (document.getElementById('day').options.length != 1)
            {
                getDays();
            }
//            alert(dayArr[document.getElementById('month').value-1]);
        }

        function dayClick()
        {
           // alert("click!");
            if (document.getElementById('year').options.length == 1 ||document.getElementById('month').options.length == 1)
            {
                return;
            }
            if(document.getElementById('day').options.length == 1)
            {
                getDays();
            }
        }

        function getMonths()
        {
            document.getElementById('month').options.length = 0;
            for (var i = 1; i <= 12; i++) 
            {
                opt = document.createElement("option");
                opt.value = i;
                opt.text = monArr[i - 1];
                document.getElementById('month').options.add(opt);
            }
        }

        function getDays() 
        {
            document.getElementById('day').options.length = 0;
            var day = document.getElementById('day');
            var mon = document.getElementById('month').value;
            var ye = document.getElementById('year').value;
            var dayNum = dayArr[mon-1];

            if (((ye % 100 == 0 && ye % 400 == 0) || (ye % 100 != 0 && ye % 4 == 0)) && mon == 2)
                dayNum -= 1;
            for(var i=1;i<=dayNum;i++)
            {
                var opt = document.createElement("option");
                opt.value = i;
                opt.text = i;
                day.options.add(opt);
            }
        }