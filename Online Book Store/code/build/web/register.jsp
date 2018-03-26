<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8" />
<title>Register</title>
<link href="css/register.css" rel="stylesheet" type="text/css" media="screen" />
<script type="text/javascript" src="js/date.js"></script>
</head>
<body onload="yearClick();monthClick();dayClick();">
    <div id="container">
        <div id="header">
            <div id="headerLine">
            </div>
            <div id="logo">
                <img id="logo_img" src="images/logo.png" alt="logo" width="215px" height="60px"/>
            </div>
        </div>
        <div id="content">
            <div id="form">
                <form name="info_collection" method="post" action="<%= request.getContextPath()%>/Register">
                    <div id="box1" class="box">
                        <div class="info"><input name="username" type="text" class="inputBox"/></div>
                        <div class="labelBox"><span class="label">UserName:</span></div>
                    </div>
                    
                    <div id="box2" class="box">
                        <div class="info"><input name="email" type="text" class="inputBox"/></div>
                        <div class="labelBox"><span class="label">E-mail</span></div>
                    </div>
                    
                    <div id="box3" class="box">
                        <div class="info"><input name="phone" type="text" class="inputBox"/></div>
                        <div class="labelBox"><span class="label">phone</span></div>
                    </div>
                    
                    <div id="box4" class="box">
                        <div class="info"><input name="possword" type="password" class="inputBox"/></div>
                        <div class="labelBox"><span class="label">Password:</span></div>
                    </div>
                    <div id="box5" class="box">
                        <div class="info"><input name="password2" type="password" class="inputBox"/></div>
                        <div class="labelBox"><span class="label">Confirm password:</span></div>
                    </div>
                    <div id="box6" class="box">
                        <div class="info">
                            <input type="radio" name="gender" value="1" checked="checked" class="inputRadio"/><span class="radioLabel">Male</span>
                            <input type="radio" name="gender" value="0" class="inputRadio"/><span  class="radioLabel">Female</span>
                        </div>
                        <div class="labelBox"><span class="label">Gender:</span></div>
                    </div>
                    <div id="box7" class="box">
                        <div class="info">
                            <select name="year" id="year" class="select" onchange="yearChange()">
                                <option class="option">Year</option>
                            </select>
                            <select name="month" id="month" class="select" onchange="monthChange()">
                                <option class="option">Month</option>
                            </select>
                            <select name="day" id="day" class="select">
                                <option class="option">Day</option>
                            </select>
                        </div>
                        <div class="labelBox"><span class="label">Birthday:</span></div>
                    </div>
                    <div id="box8" class="box">
                        <div class="info"><input type="submit" value="Register!" id="button" /></div>
                        <div class="labelBox"><span class="label">&nbsp;</span></div>
                    </div>
                </form>
            </div>
        </div>
        <div id="footer"></div>
    </div>
</body>
</html>