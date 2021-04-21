
function regist()
{
    var reg =  /^[A-Za-z0-9\u4e00-\u9fa5]+@[a-zA-Z0-9_-]+(\.[a-zA-Z0-9_-]+)+$/
    var uname = document.getElementById("username");
    var upass = document.getElementById("password");
    var urepass = document.getElementById("repassword");
    var email = document.getElementById("Email");

    if(uname.value.length == 0 )
    {
        window.alert("还没有输入用户名");
        return;
    }else if(upass.value.length==0){
        window.alert("还没有输入密码");
        return;
    }else if(urepass.value.length==0){
        window.alert("请再次输入密码");
        return;
    }else if(email.value.length==0){
        window.alert("请输入你的邮件");
        return;
    }
    else if(upass.value != urepass.value){
        window.alert("两次密码不一致,请重新输入")
        return;
    }else{
        var st = reg.test(email.value);
        if(st){
            window.alert("登录成功");
            return;
        }
        else{
            window.alert("邮箱格式错误");
            return;
        }
    }
}