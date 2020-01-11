alert("Hello World!");
var check = confirm("Do you really want to delete?");
alert(check);
var name=prompt("Enter your name: ");
if (name != null && name!='')
    console.log('Hello '+name);

function mouseEnter()
{
  var title = document.getElementById("title");
  title.style.color = "red";
}

function mouseLeave()
{
  var title = document.getElementById("title");
  title.style.color = "black";
}

function changeItems()
{
  var news = document.getElementsByClassName("news");
  var items = news[0].getElementsByTagName("li");
  for (var i = 0; i < items.length; i++)
  {
    var value = i + 1;
    items[i].innerHTML = "Item " + value;
  }
}

function myLoad()
{
  var title = document.getElementById("title");
  title.addEventListener("mouseenter", mouseEnter);
  title.addEventListener("mouseleave", mouseLeave);

  var button = document.getElementById("button");
  button.addEventListener("click", changeItems);
}

document.addEventListener("DOMContentLoaded", myLoad);
