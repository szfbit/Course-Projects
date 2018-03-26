<%@page import="beanClass.User"%>
<%@page import="beanClass.PurRecord"%>
<%@page import="java.util.Random"%>
<!DOCTYPE>
<html>
<head>
<title>Payment</title>
<link href="css/wrapper.css" rel="stylesheet" type="text/css" media="screen" />
<link href="css/pay/payment.css" rel="stylesheet" type="text/css" media="screen" />
</head>
<jsp:useBean id="cart" type="beanClass.Cart" scope="session" />
<jsp:useBean id="account" type="beanClass.User" scope="session"/>
<body>
	<div id="wrapper">
		<div id="upper">
			<div id="logoBlock">
				<img id="logo" src="images/logo.png"/>
			</div>

			<div id="search">
                            <form action="<%= request.getContextPath()%>/Search" method="POST">
				<img id="searchImage" src="images/search.png"/>
                                <select id="selectS" name="tp">
                                    <option value="Name">Name</option>
                                    <option value="Author">Author</option>
                                    <option value="BookID">BookID</option>
                                    <option value="Publisher">Publisher</option>                               
                                </select>
                                <input name="keyWd" id="searchText" type="text" placeholder="Search" />
				<button id="searchButton" type="submit">Search</button> 
                            </form>
			</div>

			<nav id="loginReg">
				<%if(session.getAttribute("login").equals("false")){ %>
				<a href="login.jsp">log in</a>
				<a href="register.jsp">Register</a>
                            <%}else{%>
                            <a href="userInfo.jsp"><jsp:getProperty name="account" property="userName" /></a>
                            <a href="Logout">Log out</a>
                            <%}%>
			</nav>

			<div id="cartCheck">
				<button id="cartB" onclick="location.href='cart.do'">Cart</button>
				<button id="checkB" onclick="location.href='pay.do'">Check</button>
			</div>
		</div>
		<div id="menu">
			<ul class="menuClass">
				<li><a href="<%= request.getContextPath()%>/index">Homepage</a></li>
				<li><a href="<%= request.getContextPath()%>/Classification">Classification</a></li>
				<li><a href="<%= request.getContextPath()%>/Onsale">On Sale</a></li>
			</ul>
		</div>
        <div id="content">
            <%if(request.getParameter("action")==null){%>
            <%
                int level=account.getLevel();
                double disRatio=0.05*(level-1);
                double total=0;
                double dis;
                double actTotal;
                for(int i=0;i<=cart.getCount()-1;i++)
                    total+=cart.getLists().get(i).getCurrent_price()*cart.getNum().get(i);
                dis=total*disRatio;
                String s;
                
                s = String.format("%06d", Math.abs(new Random().nextInt()%1000000));
                total=Math.round(total*100)*1.0/100;
                dis=Math.round(dis*100)*1.0/100;
                actTotal=total-dis;
            %>
                <div id="form">
                    <form name="info_collection" method="post" action="#">
                        <div id="box1" class="box">
                            <div class="info"><span id="payer" class="text"><%=account.getUserName()%></span></div>
                            <div class="labelBox"><span class="label">Payer:</span></div>
                        </div>
                        <div id="box2" class="box">
                            <div class="info"><span id="orderInd" class="text">#<%=s%></span></div>
                            <div class="labelBox"><span class="label">Order Index:</span></div>
                        </div>
                        <div id="box3" class="box">
                            <div class="info"><span id="totalAmount" class="text">$<%=total%></span></div>
                            <div class="labelBox"><span class="label">Total Amount:</span></div>
                        </div>
                        <div id="box4" class="box">
                            <div class="info"><span id="discount" class="text">$<%=dis%></span></div>
                            <div class="labelBox"><span class="label">Discount:</span></div>
                        </div>
                        <div id="box5" class="box">
                            <div class="info"><span id="actAmount" class="text">$<%=actTotal%></span></div>
                            <div class="labelBox"><span class="label">Actual Payment:</span></div>
                        </div>
                        <div id="box6" class="box">
                            <input type="button" value="Check" class="button" onclick="location.href='pay.do?action=check&total=<%=total%>'" />
                            <input type="button" onclick="location.href='<%=request.getHeader("REFERER")%>'" value="View Cart" class="button" />
                        </div>
                </form>
            </div>
            <%}else{%>
                <div id="content">
                    <p id="result">Payment is successful! Following is the payment list: </p>
                    <br /><br />

                    <div id="tableContainer">
                        <table id="table">
                            <thead>
                                <tr>
                                    <td class="title">Title</td>
                                    <td class="price">Price</td>
                                    <td class="type">Type</td>
                                    <td class="qty">Quantity</td>
                                    <td class="subt">Payment:</td>
                                    <td class="sending">Sending Status</td>
                                </tr>                    
                            </thead>
                            <tbody>
                                <%PurRecord rec=(PurRecord)request.getAttribute("record");
                                    double total=0;
                                    for(int i=0;i<=rec.getCount()-1;i++)
                                        total+=rec.getCharList().get(i);
                                    total=Math.round(total*100)*1.0/100;
                                    double perPoint=((User)session.getAttribute("account")).getPoint();
                                    perPoint=Math.round(perPoint*100)*1.0/100;
                                %>
                                
                                
                                <%for(int i=0;i<=rec.getCount()-1;i++){%>
                                <tr>
                                    <td class="title"><%=rec.getbList().get(i).getName()%></td>
                                    <td class="price"><%=rec.getbList().get(i).getCurrent_price()%></td>
                                    <td class="type"><%=rec.getbList().get(i).getCat()%></td>
                                    <td class="qty"><%=rec.getNum().get(i)%></td>
                                    <td class="subtotal"><%=rec.getCharList().get(i)%></td>
                                    <% String send;
                                        if(rec.getCharList().get(i)!=0)
                                            send="sending";
                                        else
                                            send="Out of Stock";
                                    %>
                                    <td class="sending"><b><%=send%></b></td>
                                </tr>
                                <%}%>
                                
                            </tbody>
                            <tr>
                                <td colspan=6 class="sum"><span class="summ">Actual Payment: $<%=total%></span></td>
                            </tr>
                            <tr>
                                <td colspan=6 class="sum"><span class="summ">Remaining Points: $<%=perPoint%></span></td>
                            </tr>
                            <tr>            
                                <td colspan=6 class="sum"><span class="summ">Account Level: <jsp:getProperty name="account" property="level" /></span></td>
                            </tr>
                        </table>
                    </div>
                </div>  
            <%}%>
        </div>
		<div id="footer">
			<p>Author: WANG Yiji(52639040), ZOU Shaokun(52639296)</p>
			<p>All Rights Reserved</p>
		</div>
	</div>
</body>
</html>