var click = new Array(50);
var clickp = new Array(50);

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
    for(var j = 0;j < 50; j++)
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

function editp(i)
{
    document.getElementById("Btnp"+i).innerHTML = "Saving...";
}

function savep(i)
{
    document.getElementById("Btnp"+i).innerHTML = "Edit";
    document.getElementById("fp"+i).submit();
}

function clickBp(i)
{
    for(var j = 0;j < 50; j++)
    {
        clickp[j] = false;
    }
    
    if(!clickp[i])
    {
        clickp[i] = !clickp[i];
        editp(i);
        
    }
    else
    {
        clickp[i] =!clickp[i];
        savep(i);
        
    }
}