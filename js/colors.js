$(document).ready(function()
{
  if (!document.body) document.body = $('#body').get(0); 
  $("tr:even").css("background-color", "#66CCFF");
  $("tr:odd").css("background-color", "#C0D9D9");
});
