var interval=0;

$(document).ready(function()
{
    $('button').click(function()
    {
        // $('#title').css({'color':'red','opacity':'0.5'});
       
        $('.content').html('This is my content');
        $('#title').css('opacity','1');

        var interval= setInterval(function()
        {
            var oldOpacity = $('#title').css('opacity');
            if (oldOpacity==0)
            {
                clearInterval(interval);
            }
            else
            {
                $('#title').css('opacity',oldOpacity - 0.1);   
            }
        },100);
    })
})