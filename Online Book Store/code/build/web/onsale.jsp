<!DOCTYPE>
<html>
<head>
<title>Onsale</title>
<link href="css/wrapper.css" rel="stylesheet" type="text/css" media="screen" />
<link href="css/onsale.css" rel="stylesheet" type="text/css" media="screen" />
</head>
<jsp:useBean id="sale0" type="beanClass.Book" scope="request"/>
<jsp:useBean id="sale1" type="beanClass.Book" scope="request"/>
<jsp:useBean id="sale2" type="beanClass.Book" scope="request"/>
<jsp:useBean id="sale3" type="beanClass.Book" scope="request"/>
<jsp:useBean id="sale4" type="beanClass.Book" scope="request"/>
<jsp:useBean id="sale5" type="beanClass.Book" scope="request"/>
<jsp:useBean id="sale6" type="beanClass.Book" scope="request"/>
<jsp:useBean id="sale7" type="beanClass.Book" scope="request"/>
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

		<div class="proverbClass">
			<img id="proverb" src="images/proverb.png"/>
		</div>
 		
 		<div id="hotB">
 			<div class="titleStyle">Onsale</div>
 			<table id="hB">
 				<tr>
                                    <td>
                                            <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=sale0.getId()%>">
                                                    <img src="images/bookImages/<%=sale0.getId()%>.jpg"/>
                                            </a>
                                    </td>

                                    <td>
                                            <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=sale1.getId()%>">
                                                    <img src="images/bookImages/<%=sale1.getId()%>.jpg"/>
                                            </a>
                                    </td>

                                    <td>
                                            <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=sale2.getId()%>">
                                                    <img src="images/bookImages/<%=sale2.getId()%>.jpg"/>
                                            </a>
                                    </td>

                                    <td>
                                            <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=sale3.getId()%>">
                                                    <img src="images/bookImages/<%=sale3.getId()%>.jpg"/>
                                            </a>
                                    </td>
 				</tr>

 				<tr id="bookName">
 					<td>
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=sale0.getId()%>">
                                                        <%=sale0.getName()%>
                                                </a>
                                        </td>

                                        <td>
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=sale1.getId()%>">
                                                        <%=sale1.getName()%>
                                                </a>
                                        </td>

                                        <td>
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=sale2.getId()%>">
                                                        <%=sale2.getName()%>
                                                </a>
                                        </td>

                                        <td>
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=sale3.getId()%>">
                                                        <%=sale3.getName()%>
                                                </a>
                                        </td>
 				</tr>     
                                
 				<tr>
 					<td><%=sale0.getAuthor()%></td>
 					<td><%=sale1.getAuthor()%></td>
 					<td><%=sale2.getAuthor()%></td>
 					<td><%=sale3.getAuthor()%></td>
 				</tr>
                                
                                <tr>
                                        <td><span class="lastP">$<%=sale0.getLast_price()%></span></td>
 					<td><span class="lastP">$<%=sale1.getLast_price()%></span></td>
 					<td><span class="lastP">$<%=sale2.getLast_price()%></span></td>
 					<td><span class="lastP">$<%=sale3.getLast_price()%></span></td>
 				</tr>
                                
 				<tr>
                                        <td><span class="curP">$<%=sale0.getCurrent_price()%></span></td>
 					<td><span class="curP">$<%=sale1.getCurrent_price()%></span></td>
 					<td><span class="curP">$<%=sale2.getCurrent_price()%></span></td>
 					<td><span class="curP">$<%=sale3.getCurrent_price()%></span></td>
 				</tr>
 			</table>
                        <hr/>
                        <table id="rB">
 				<tr>
                                    <td>
                                            <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=sale4.getId()%>">
                                                    <img src="images/bookImages/<%=sale4.getId()%>.jpg"/>
                                            </a>
                                    </td>

                                    <td>
                                            <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=sale5.getId()%>">
                                                    <img src="images/bookImages/<%=sale5.getId()%>.jpg"/>
                                            </a>
                                    </td>

                                    <td>
                                            <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=sale6.getId()%>">
                                                    <img src="images/bookImages/<%=sale6.getId()%>.jpg"/>
                                            </a>
                                    </td>

                                    <td>
                                            <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=sale7.getId()%>">
                                                    <img src="images/bookImages/<%=sale7.getId()%>.jpg"/>
                                            </a>
                                    </td>
 				</tr>

 				<tr id="bookName">
 					<td>
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=sale4.getId()%>">
                                                        <%=sale4.getName()%>
                                                </a>
                                        </td>

                                        <td>
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=sale5.getId()%>">
                                                        <%=sale5.getName()%>
                                                </a>
                                        </td>

                                        <td>
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=sale6.getId()%>">
                                                        <%=sale6.getName()%>
                                                </a>
                                        </td>

                                        <td>
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=sale7.getId()%>">
                                                        <%=sale7.getName()%>
                                                </a>
                                        </td>
 				</tr>     
                                
 				<tr>
 					<td><%=sale4.getAuthor()%></td>
 					<td><%=sale5.getAuthor()%></td>
 					<td><%=sale6.getAuthor()%></td>
 					<td><%=sale7.getAuthor()%></td>
 				</tr>
                                 
                                <tr>
                                        <td><span class="lastP">$<%=sale4.getLast_price()%></span></td>
                                        <td><span class="lastP">$<%=sale5.getLast_price()%></span></td>
                                        <td><span class="lastP">$<%=sale6.getLast_price()%></span></td>
                                        <td><span class="lastP">$<%=sale7.getLast_price()%></span></td>
                                </tr>
 				<tr>
 					<td><span class="curP">$<%=sale4.getCurrent_price()%></span></td>
                                        <td><span class="curP">$<%=sale5.getCurrent_price()%></span></td>
                                        <td><span class="curP">$<%=sale6.getCurrent_price()%></span></td>
                                        <td><span class="curP">$<%=sale7.getCurrent_price()%></span></td>
 				</tr>
 			</table>
 		</div>

		<div id="footer">
			<p>Author: WANG Yiji(52639040), ZOU Shaokun(52639296)</p>
			<p>All Rights Reserved</p>
		</div>

	</div>
</body>
</html>