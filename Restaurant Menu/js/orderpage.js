	var isAdded = new Array(false, false, false, false, false, false);
	var dishName = new Array("Foie Gras Saute", "Bouillabaisse", "Blanquette De Veau", "Steak Fries", "Valen?ay (cheese)", "Lobster Bisque");
	var price = new Array(32, 27, 30, 24, 35, 28);
	var numOfR = 1;
	var number = new Array;
	var total = 0;
	var tableN = (location.search).split('?')[1];

	function changeTabNum()
	{
		document.getElementById("tabNum").innerHTML = tableN;
	}
	
	function getTotal()
	{
		document.getElementById("totMoney").innerHTML = total;
	}
	
	
	function createList(index)
	{	
		var addPrice = price[index];
		var addName = dishName[index];
		
		
		if(isAdded[index] == false)
		{
			var addRow = document.getElementById("finalOrder").insertRow(numOfR);
			var addRef = addRow.insertCell(0);
			var addDesc = addRow.insertCell(1);
			var addQty = addRow.insertCell(2);
			var addHK = addRow.insertCell(3);
			
			number[index] = numOfR;
			isAdded[index] = true;
			
			addRef.innerHTML = numOfR;
			addDesc.innerHTML = addName;
			addQty.innerHTML = document.getElementById("s" + index).value;
			addHK.innerHTML = parseInt(document.getElementById("s" + index).value) * addPrice;
			
			numOfR++;
			total += parseInt(document.getElementById("s" + index).value) * addPrice;
		}
		else
		{
			var changedT = document.getElementById("finalOrder").rows[number[index]].cells;
			changedT[2].innerHTML = parseInt(changedT[2].innerHTML) + parseInt(document.getElementById("s" + index).value);
			changedT[3].innerHTML = parseInt(changedT[3].innerHTML) + parseInt(document.getElementById("s" + index).value) * addPrice;
			total += parseInt(document.getElementById("s" + index).value) * addPrice;
		}
		document.getElementById("theBelow").style.display = "block";
		getTotal();
	}