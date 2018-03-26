<%@page import="beanClass.PurRecord"%>
<!DOCTYPE>
<html>
<head>
<title>Remark</title>
<link href="css/wrapper.css" rel="stylesheet" type="text/css" media="screen" />
<link href="css/navigation.css" rel="stylesheet" type="text/css" media="screen" />
<link href="css/myPurchase.css" rel="stylesheet" type="text/css" media="screen" />
</head>
<jsp:useBean id="account" type="beanClass.User" scope="session"/>
<jsp:useBean id="record" type="PurRecord" scope="request" />
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
 		
 		<div id="nav" class="navClass">
 			<a href="<%= request.getContextPath()%>/userInfo.jsp">User information</a><hr/>
 			<a href="#">Purchase record</a><hr/>
 			<a href="<%= request.getContextPath()%>/revisePswd.jsp">Revise password</a><hr/>
 			<a href="fav.do">Favorite</a><hr/>
 			<a href="<%= request.getContextPath()%>/myRemark.jsp">My remark</a><hr/>
 		</div>

 		<div id="remarkB">
                    <div id="tableContainer">
                        <table id="table">
                        <thead>
                            <tr>
                                <td class="pid">Purchase ID</td>
                                <td class="bid">Book ID</td>
                                <td class="qty">Quantity</td>
                                <td class="subt">Charge</td>
                                <td class="sending">Sending Status</td>
                                <td class="ref">Refund</td>
                            </tr>                    
                        </thead>
                        <tbody>
                            <%double total=0;%>
                            <%for(int i=0;i<=record.getCount()-1;i++){%>
                            <tr>
                                <td class="pid"><%=record.getPidList().get(i)%></td>
                                <td class="bid"><%=record.getbList().get(i).getId()%></td>
                                <td class="qty"><%=record.getNum().get(i)%></td>
                                <td class="subt"><%=record.getCharList().get(i)%></td>
                                <td class="sending"><b>
                                    <%if(record.getCharList().get(i)==0){%>
                                        Out of Stack
                                    <%}else{%>
                                        Sending
                                    <%}%>
                                    </b>
                                </td>
                                <td class="ref">
                                    <%if(record.getRefList().get(i)==0){%>
                                        <%int type;String url;%>
                                        <%if(record.getCharList().get(i)!=0)
                                            type=0;
                                        else
                                            type=1;
                                        url="purRecord.do?action=refund&pid="+record.getPidList().get(i)+"&type="+type;
                                        %>
                                        <a href="<%=url%>">Refund</a>
                                    <%}else if(record.getRefList().get(i)==1){%>
                                        Sending...
                                    <%}else if(record.getRefList().get(i)==2||record.getRefList().get(i)==3){%>
                                        Approved!
                                    <%}else{%>
                                        Rejected.
                                    <%}%> 
                                </td>
                            </tr>
                                <%if(record.getRefList().get(i)!=2)//2 for refunded real things rather than stock
                                    total+=record.getCharList().get(i);
                                    total=Math.round(total*100)*1.0/100;
                                %>
                            <%}%>
                        </tbody>
                            <tr>
                                <td colspan=6 class="sum"><span class="summ">Total Payment: $<%=total%></span></td>
                            </tr>
                            <tr>
                                <td colspan=6 class="sum"><span class="summ"><%=record.getCount()%> item(s)</span></td>
                            </tr>
                        </table>
                    </div>             
		</div>	
 		
		<div id="footer">
			<p>Author: WANG Yiji(52639040), ZOU Shaokun(52639296)</p>
			<p>All Rights Reserved</p>
		</div>

	</div>
</body>
</html>