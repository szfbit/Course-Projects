		var ellip = new Array(".", "..", "...", "....");
		var timer = 5; 
		var i = 0;
		var inter;
		var interE;

		function timeNow()
		{
			inter = setInterval("redirect()", 1000);
			interE =  setInterval("animation()", 500);
		}

		function animation()
		{
			if(i >= 4)
			{
				i %= 4;
			}
			document.getElementById("ell").innerHTML = ellip[i];
			i++;
		}

		function redirect()
		{
			if(timer <= 0)
			{
//				alert("redirect");
				clearInterval(inter);
				clearInterval(interE);
                                location.replace("index");
			}
			else
			{
				timer--;
				document.getElementById("time").innerHTML = timer;
			}
		}