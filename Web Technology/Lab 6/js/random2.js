function drawNumbers()
{
    var table=document.getElementsByTagName('table');
    if (table.length>0)
    {
        table[0].parentNode.removeChild(table[0]);
    }

    var table = document.createElement('table');
    var tr = document.createElement('tr');
    table.appendChild(tr);

    for (var i=0;i<5; i++)
    {
        var r= Math.ceil(Math.random()*20);
        var td=document.createElement('td');
        var textNode = document.createTextNode(r);
        td.appendChild (textNode);
        tr.appendChild(td);
    }
    document.getElementsByTagName('body')[0].appendChild(table);
}

function myLoad()
{
    var button = document.getElementsByTagName("button");
    button[0].addEventListener("click",drawNumbers);
}

document.addEventListener("DOMContentLoaded", myLoad);