
function regist()
{
    var uname = document.getElementById("username");
    var upass = document.getElementById("password");
    var urepass = document.getElementById("repassword");
    var email = document.getElementById("Email");

    var reason = "";
    reason += validateUsername(uname);
    reason += validateUseroword(upass);
    reason += validateSecondword(urepass);
    reason += validateEmail(email);
    reason += validateCheckword(upass,urepass);
    reason += checkEmail(email);
    if(reason != ""){
        alert("输入有误:\n"+reason);
    }else{
        alert("登录成功!");
    }
}
function validateUsername(fld){
    var error = "";
    if(fld.value == null || fld.value == ""){
        error = "用户名不能为空! \n";
    }
    return error;
}
function validateUseroword(fld){
    var error = "";
    if(fld.value == null || fld.value == ""){
        error = "密码不能为空! \n";
    }
    return error;
}
function validateSecondword(fld){
    var error = "";
    var tempError= validateUseroword(document.getElementById("password"));
    if(tempError == "" ){ // 输入了密码
        if((fld.value == null || fld.value == "")){
            error = "请再次输入密码 \n";
        }
    }
    return error;
}
function validateCheckword(fld1,fld2){
    var error = "";
    var temp = validateSecondword(document.getElementById("repassword"));
    if(temp == ""){
        if(fld1.value != fld2.value){
            error = "两次密码不一致! \n";
        }
    }
    return error;
}
function validateEmail(fld){
    var error = "";
    if(fld.value == "" || fld.value == ""){
        error = "邮箱不能为空! \n";
    }
    return error;
}
function checkEmail(fld){
    var reg =  /^[A-Za-z0-9\u4e00-\u9fa5]+@[a-zA-Z0-9_-]+(\.[a-zA-Z0-9_-]+)+$/;
    var error = "";
    if(validateEmail(document.getElementById("Email")) == ""){
        if(!reg.test(fld.value)){
            error = "邮箱格式不正确! \n";
        }
    }
    return error;
}