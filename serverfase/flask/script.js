function ajaxme(){
  var xhttp = new XMLHttpRequest();
  
  xhttp.onreadystatechange = function() {
    if ( this .readyState === 4 &&  this.status === 200) {
      document.getElementById("details").innerHTML = this.responseText;
    }
  };
  
  xhttp.open("GET", "ajaxServlet", true);
  xhttp.send();
}

function hoverText(){
  var elem = document.getElementById("hovertext");
  elem.style = "color: "
}
