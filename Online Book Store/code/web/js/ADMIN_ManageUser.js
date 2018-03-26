var click = new Array();

function edit(i)
{
    document.getElementById("Btn"+i).innerHTML = "Saving...";
}

function save(i)
{
    document.getElementById("Btn"+i).innerHTML = "Edit";
    document.getElementById("f"+i).submit();
}

function clickB(i)
{
    for(var j = 0;j < i; j++)
    {
        click[j] = false;
    }
    
    if(!click[i])
    {
        click[i] = !click[i];
        edit(i);
        
    }
    else
    {
        click[i] =!click[i];
        save(i);
        
    }
}