function check()
{
	if(document.getElementById("newP").value !== document.getElementById("conP").value)
	{
		document.getElementById("wrong").style.display = "block";
		document.getElementById("blank").style.display = "none";
		document.getElementById("newP").value = "";
		document.getElementById("conP").value = "";
	}
	else if((document.getElementById("newP").value === "") || (document.getElementById("newP").value ===""))
	{
		document.getElementById("blank").style.display = "block";
		document.getElementById("wrong").style.display = "none";
		document.getElementById("newP").value = "";
		document.getElementById("conP").value = "";
	}
	else
	{
            if(confirm("Change the password?"))
            {
		document.getElementById("pswd").submit();
                alert("Password revised successfully!");
            }
            else
            {
                document.getElementById("newP").value = "";
		document.getElementById("conP").value = "";
                alert("Password not revised");
            }
	}
}

