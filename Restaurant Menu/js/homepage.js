	var position1 = 0;
	var position2 = 0;
	var order = 1;
	window.onload = setMoving;
	
	
	function rotate()
	{
		var length = 1200;
		
		var begin = document.getElementById("scroll_begin");
		var end = document.getElementById("scroll_end");
		end.innerHTML = begin.innerHTML;
		begin.style.right = position1 + "px";
		end.style.right = position2-540 + "px";
		if(position1 < length-140)
		{
			position1 += 5;
		}
		if(position1 >= length-140)
		{
			position1 = 0;
		}
		
		if(position2 < length-140)
		{
			position2 += 5;
		}
		if(position2 >= length-140)
		{
			position2 = 0;
		}
	}
	
	function setMoving()
	{
		var run = setInterval("rotate();", 50);
		document.getElementById("promotion").onmouseover = function(){clearInterval(run);}
		document.getElementById("promotion").onmouseout = function(){run = setInterval("rotate();", 50);}
	}

	function changeVideo()
	{
		var video = document.getElementById('videoG');
		var name = new Array("food", "nature", "wonders");
		
		video.src = "http://courses.cs.cityu.edu.hk/cs2204/" + name[order] + ".mp4";
		order = (order == 2)?0:(order+1);
	}