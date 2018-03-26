	var isConfirm = false;
	
	function changeStar(n)
	{
		if(!isConfirm)
		{
			for(var i = 1; i <= n; i++)
			{
				document.getElementById("s"+i).src = "images/remarkImages/star.png";
			}
		}
	}

	function resetS()
	{
		if(!isConfirm)
		{
			for(var i = 1; i <= 5; i++)
			{
				document.getElementById("s"+i).src = "images/remarkImages/star_B.png";
			}
		}
	} 

	function confirm(n)
	{
		isConfirm = !isConfirm;
//                alert(document.getElementById("star").value);
                document.getElementById("star").value = n;
//                alert(document.getElementById("star").value);
	}