
// Set the date we're counting down to
var countDown = [new Date("Sep 8, 2022 17:10:00").getTime(), new Date("Oct 7, 1952 09:30:00").getTime(), new Date("Nov 22, 1963 20:30:00").getTime(), new Date("Jan 26, 2020 16:45:00").getTime()];

// Update the count down every 1 second
var x = setInterval(function() {

  // Get today's date and time
  var now = new Date().getTime();

  // Find the distance between now and the count down date
  distance = []
  for(var i = 0; i < countDown.length; i++){
    distance.push(now - countDown[i]);
  }

  var days = [];
  var hours = [];
  var minutes = [];
  var seconds = [];
  for(var i = 0; i < countDown.length; i++){
    days.push(Math.floor(distance[i] / (1000 * 60 * 60 * 24)));
    hours.push(Math.floor((distance[i] % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60)));
    minutes.push(Math.floor((distance[i] % (1000 * 60 * 60)) / (1000 * 60)));
    seconds.push(Math.floor((distance[i] % (1000 * 60)) / 1000));
  }

  for (var i = 0; i < countDown.length; i++) {
    document.getElementById("element_" + i).innerHTML = days[i] + " days " + hours[i] + " hours "
  + minutes[i] + " minutes " + seconds[i] + " seconds ";
  }
}, 1000);
