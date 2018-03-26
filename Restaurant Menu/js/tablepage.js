	var tableN;
	var order = 1;
	var isChosen = false;
	var infoDate = new Array;
	var infoTime = new Array;
	var isValid = new Array(6);
	

	
	function reset()
	{
		for(var i = 1; i <= 12; i++)
		{
			document.getElementById("td" + i).style.backgroundColor = "#3399FF";
			document.getElementById("td" + i).style.opacity = 0.6;
		}
	}
  
	function changeColor(id)
	{
		reset();
		tableN = id.split('d')[1];
		document.getElementById("tableNumber").innerHTML = id.split('d')[1];
		document.getElementById("tableNumber2").innerHTML = id.split('d')[1];
		document.getElementById(id).style.backgroundColor = "#FF3300";
		document.getElementById(id).style.opacity = 1;
		isChosen = true;
	}
	
	function clearWord(id)
	{
		document.getElementById(id).value = "";
		document.getElementById(id).style.color = "black";
	}
	
	function reset2()
	{
		var text = new Array("Enter Date", "Enter Time", "Enter Name", "Enter Tel NO.");
		for(var i = 1; i <= 4; i ++)
		{
			document.getElementById("input" + i).style.color = "grey";
			document.getElementById("input" + i).value = text[i-1];
		}
		document.getElementById("errorMsg").innerHTML = "Description Box";
	}
	
	function isChosenYet()
	{
		if(!isChosen)
		{
			alert("Please choose a table first");
			reset2();
		}
	}
	
	function createTable()	
	{
		if(isChosen)
		{
			var addRow = document.getElementById("bookingDetails").insertRow(order+1);
			var addDate = addRow.insertCell(0);
			var addTime = addRow.insertCell(1);
			var addPerson = addRow.insertCell(2);	
			var addContact = addRow.insertCell(3);
			var string;
			addDate.innerHTML = document.getElementById("input1").value;
			var timeN = document.getElementById("input2").value;
			
			if(parseInt(timeN.split(':')[0]) > 12)
			{
				if(parseInt(timeN.split(':')[0])< 22)
				{
					string = "0" + timeN.split(':')[0]%12 + ":" + timeN.split(':')[1] + " pm";
				}
				else
				{
					string = timeN.split(':')[0]%12 + ":" + timeN.split(':')[1] + " pm";
				}
			}
			else
			{
				if(parseInt(timeN.split(':')[0]) < 10)
				{
					string = "0" + document.getElementById("input2").value + " am";
				}
				else
				{
					string = document.getElementById("input2").value + " am";
				}
			}
			
			addTime.innerHTML = string;
			addPerson.innerHTML = document.getElementById("input3").value;
			addContact.innerHTML = document.getElementById("input4").value;
			infoDate[order-1] = document.getElementById("input1").value
			infoTime[order-1] = document.getElementById("input2").value;
			order++;
		}
		else
		{
			isChosenYet();
		}
	}
	
	
	function isLeapYear(year)
	{
		if(year%400 ==0)
		{
			return true;
		}
		else if(year%100 == 0)
		{
			return false;
		}
		else if(year%4 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	

	function isValidF()
	{
		for(var i = 0;i < 6; i++)
		{
			isValid[i] = true;
		}
		
		var date = document.getElementById("input1").value;
		var time = document.getElementById("input2").value;
		var name = document.getElementById("input3").value;
		var contactN = document.getElementById("input4").value;
		var day = date.split('/')[0];
		var month = date.split('/')[1];
		var year = date.split('/')[2];
		var hour = time.split(':')[0];
		var minute = time.split(':')[1];
		
		var nowTime = new Date();
		var nowY = parseInt(nowTime.getYear())+1900;
		var nowM = nowTime.getMonth()+1;
		var nowD = nowTime.getDate();
		var nowH = nowTime.getHours();
		var nowMin = nowTime.getMinutes();
		

		if(date == "" ||  date == "Enter Date")
		{
			isValid[0] = false;
		}
		
		if(time == "" || time == "Enter Time")
		{
			isValid[1] = false;
		}
		
		if((name == "")|| (name == "Enter Name"))
		{
			isValid[5] = false;
		}
		
		if(!isLeapYear(parseInt(year)))
		{	
			if(parseInt(month) == 2)
			{
				if(parseInt(day) > 28)
				{
					isValid[0] = false;
				}
			}
		}
		
		if(isNaN(year) || isNaN(month) || isNaN(day))
		{
			isValid[0] = false;
		}
		
		if(isNaN(hour) || isNaN(minute))
		{
			isValid[1] = false;
		}
		
		if(isNaN(contactN))
		{
			isValid[2] = false;
		}
		
		if(parseInt(month) <= 0 || parseInt(month) > 12)
		{
			isValid[0] = false;
		}
		
		if(parseInt(day) <= 0)
		{
			isValid[0] = false;
		}

		switch(parseInt(month))
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if(day > 31)
				{
					isValid[0] = false;
				}
				break;
			case 2:
				if(day > 29)
				{
					isValid[0] = false;
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if(day > 30)
				{
					isValid[0] = false;
				}
				break;
		}
			
		
		if(parseInt(hour) < 0 || parseInt(hour) >= 24)
		{
			isValid[1] = false;
		}
		
		if(parseInt(minute) < 0 || parseInt(minute) > 59)
		{
			isValid[1] = false;
		}
		
		if(parseInt(year) < parseInt(nowY))
		{
			isValid[0] = false;
		}
		
		if((parseInt(year) == parseInt(nowY)) && (parseInt(month) < parseInt(nowM)))
		{
			isValid[0] = false;
		}
		
		if((parseInt(year) == parseInt(nowY)) && (parseInt(month) == parseInt(nowM)) && (parseInt(day) < parseInt(nowD)))
		{
			isValid[0] = false;
		}
		
		if((parseInt(year) == parseInt(nowY)) && (parseInt(month) == parseInt(nowM)) && (parseInt(day) == parseInt(nowD)) && (parseInt(hour) < parseInt(nowH)))
		{
			isValid[4] = false;
		}
		
		if((parseInt(hour) < parseInt(nowH)))
		{
			isValid[1] = false;
		}
		
		if((parseInt(hour) == parseInt(nowH)) && (parseInt(minute) < parseInt(nowMin)))
		{
			isValid[1] = false;
		}

		
		if(parseInt(contactN.length) < 8 || contactN == "Enter Tel NO.")
		{
			isValid[2] = false;
		}
		
		if(parseInt(year) > parseInt(nowY))
		{
			isValid[4] = true;
			isValid[1] = true;
		}
		
		if((parseInt(year) == parseInt(nowY)) && (parseInt(month) > parseInt(nowM)))
		{
			isValid[4] = true;
			isValid[1] = true;
		}	
		
		if((parseInt(year) == parseInt(nowY)) && (parseInt(month) == parseInt(nowM)) && (parseInt(day) > parseInt(nowD)))
		{
			isValid[4] = true;
			isValid[1] = true;
		}	
		
		for(var i = 0; i < order-1; i++)
		{
			if(date == infoDate[i] && time == infoTime[i])
			{
				isValid[3] = false;
				break;
			}
		}
	}
	
	
	function getError()
	{
		var errorString = "";
		isValidF();
		
		var isOK = true;
		for(var i = 0; i < 6; i++)
		{
			if(isValid[i] == false)
			{
				isOK = false;
			}
			
		}
		
		if(isOK == true)
		{
			alert("booking confirmed");
			document.getElementById("errorMsg").innerHTML = "";
			createTable();
		}
		else
		{
			if(isValid[0] == false)
			{
				errorString += "<span style='color:red'>Error 1:</span>Date is invalid" + "<br/>";
			}
			
			if(isValid[1] == false || isValid[4] == false)
			{	
				errorString += "<span style='color:red'>Error 2:</span>Time is invalid" + "<br/>";
			}
			
			if(isValid[5] == false)
			{
				errorString += "<span style='color:red'>Error 3:</span>Please input name" + "<br/>";
			}
			
			if(isValid[2] == false)
			{
				errorString += "<span style='color:red'>Error 4:</span>Phone number should be 8 digits" + "<br/>";
			}
			
			if(isValid[3] == false)
			{
				errorString += "<span style='color:red'>Error 5:</span>Other guests have booked for the same time" + "<br/>";
			}
			
			document.getElementById("errorMsg").innerHTML = errorString;
			errorString = "";
			
			if(isValid[0] == false)
			{
				document.getElementById("input1").focus();
			}
			else if(isValid[1] == false)
			{
				document.getElementById("input2").focus();
			}
			else if(isValid[2] == false || isValid[4] == false)
			{
				document.getElementById("input4").focus();
			}
			else if(isValid[3] == false)
			{
				document.getElementById("input2").focus();
			}
			else if(isValid[5] == false)
			{
				document.getElementById("input3").focus();
			}
		}
		if(order > 1)
		{
			document.getElementById("readyForBook").style.display = "block";
		}
	}
		function submit()
		{
			window.open("Order_Page.html?" + tableN, "_blank");
		}
		
		function changeMsgBox(id)
		{
			clearWord(id);
			isChosenYet();
			var str = "";
			str += "<span style='color:red'>Date:</span>" + "<br/>" + "Please input the date in the format:"+ "<br/>" + "dd/mm/yy" + "<br/>";
			str += "<span style='color:red'>Time:</span>" + "<br/>" + "Please input the time in 24-hour format:" + "<br/>" + "hh:mm" + "<br/>";
			str += "<span style='color:red'>Person:</span>" + "<br/>" + "Please input your name" + "<br/>";
			str += "<span style='color:red'>Contact:</span>" + "<br/>" + "Please input your contact phone number:" + "<br/>" + "8 digits";
			document.getElementById("errorMsg").innerHTML = str;
		}
		
		function whenClickInput(id)
		{
			changeMsgBox(id);
			clearWord(id);
		}