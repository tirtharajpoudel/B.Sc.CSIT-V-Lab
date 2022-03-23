function drawNumbers()
{
    var table = document.getElementsByTagName('table');
    var tds = table[0].getElementsByTagName('td');
    for(var i = 0; i<tds.length; i++)
    {
        var r= Math.ceil(Math.random()*20);
        tds[i].innerHTML = r;
    }
}

function myLoad()
{
    var button = document.getElementsByTagName("button");
    button[0].addEventListener("click",drawNumbers);
}

document.addEventListener("DOMContentLoaded", myLoad);