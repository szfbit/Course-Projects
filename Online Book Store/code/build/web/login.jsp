<!DOCTYPE html>

<html lang="en" xmlns="http://www.w3.org/1999/xhtml">
<head>
    <meta charset="utf-8" />
    <title>Login</title>
    <link rel="stylesheet" type="text/css" href="css/login/login.css" />
    <script type="text/javascript">
        function setBoth()
        {
            document.getElementById("username").value="Email";
            document.getElementById("password").value="Password";
        }
        function userChange()
        {
            if(document.getElementById("username").value=="")
            {
                document.getElementById("username").style.color="gray";
                document.getElementById("username").value="Email";
            }
        }
        function passChange()
        {         
            if(document.getElementById("password").value=="")
            {
                document.getElementById("password").style.color="gray";
                document.getElementById("password").type="text";
                document.getElementById("password").value="Password";
            }
        }
        function userClick()
        {
            if(document.getElementById("username").value=="Email")
            {
                document.getElementById("username").style.color="black";
                document.getElementById("username").value="";
            }
        }
        
        function passClick()
        {
//            alert("userchange");
            if(document.getElementById("password").value=="Password")
            {
                document.getElementById("password").style.color="black";
                document.getElementById("password").type="password";
                document.getElementById("password").value="";
            }
        }
    </script>   
</head>
<body onload="setBoth();">
    <div id="container">
        <div id="header">
            <div id="headerLine">
            </div>
            <div id="logo">
                <img id="logo_img" src="images/logo.png" alt="logo" width="215px" height="60px"/>
            </div>
        </div>
        <div id="login_container">
            <div id="log_title">
                <h1>Sign in Account</h1>
                <span id="error" style='color: red'>
                <%if(request.getParameter("error")!=null&&Integer.parseInt(request.getParameter("error"))==1){%>
                    The email has not been registered.
                <%}else if(request.getParameter("error")!=null&&Integer.parseInt(request.getParameter("error"))==2){%>
                    Wrong password.
                <%}else if(request.getParameter("error")!=null&&Integer.parseInt(request.getParameter("error"))==3){%>
                    Information required.
                <%}%>
                </span>
            </div>
            <br />
            
            <form id="login_form" method="POST" action="check.do" onsubmit="checkForm();">
                <div><input type="text" id="username" name="username" class="inputBar" onblur="userChange()" style="color:gray;" onfocus="userClick()"/></div>
                <div><input type="text" id="password" name="password" class="inputBar" onblur="passChange()" style="color:gray;" onfocus="passClick()"/></div>
                <%if(request.getParameter("pre")==null){%>
                    <input type="hidden" name="pre" value="<%=request.getHeader("REFERER")%>" />
                <%}else{%>
                    <input type="hidden" name="pre" value="<%=request.getParameter("pre")%>" />
                <%}%>
                <br />
                <input type="submit" value="Sign in" id="submit" /> <br /><br />
                <p>
                    <span>New comer?</span>
                    <a href="register.jsp">Create a new account</a> 
                </p>
            </form>
        </div>
        <div id="store_advert">
            <div id="advert_pic">
                <img id="advert_img" src="images/flipped_login.png" alt="advert_img"/>
            </div>
            
        </div>

        <div id="footer"></div>
    </div>
</body>
</html>