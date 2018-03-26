<!DOCTYPE>
<html>
<head>
<title>Welcome</title>
<link href="css/wrapper.css" rel="stylesheet" type="text/css" media="screen" />
</head>
<jsp:useBean id="h1" type="beanClass.Book" scope="request"/>
<jsp:useBean id="h2" type="beanClass.Book" scope="request"/>
<jsp:useBean id="h3" type="beanClass.Book" scope="request"/>
<jsp:useBean id="h4" type="beanClass.Book" scope="request"/>

<jsp:useBean id="r1" type="beanClass.Book" scope="request"/>
<jsp:useBean id="r2" type="beanClass.Book" scope="request"/>
<jsp:useBean id="r3" type="beanClass.Book" scope="request"/>
<jsp:useBean id="r4" type="beanClass.Book" scope="request"/>

<jsp:useBean id="n1" type="beanClass.Book" scope="request"/>
<jsp:useBean id="n2" type="beanClass.Book" scope="request"/>
<jsp:useBean id="n3" type="beanClass.Book" scope="request"/>
<jsp:useBean id="n4" type="beanClass.Book" scope="request"/>

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
 			<div class="titleStyle">Hot</div>
 			<table id="hB">
 				<tr>
                                    <td>
                                            <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='h1' property='id'/>">
                                                    <img src="images/bookImages/<jsp:getProperty name='h1' property='id'/>.jpg"/>
                                            </a>
                                    </td>

                                    <td>
                                            <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='h2' property='id'/>">
                                                    <img src="images/bookImages/<jsp:getProperty name='h2' property='id'/>.jpg"/>
                                            </a>
                                    </td>

                                    <td>
                                            <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='h3' property='id'/>">
                                                    <img src="images/bookImages/<jsp:getProperty name='h3' property='id'/>.jpg"/>
                                            </a>
                                    </td>

                                    <td>
                                            <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='h4' property='id'/>">
                                                    <img src="images/bookImages/<jsp:getProperty name='h4' property='id'/>.jpg"/>
                                            </a>
                                    </td>
 				</tr>

 				<tr id="bookName">
 					<td>
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='h1' property='id'/>">
                                                        <jsp:getProperty name='h1' property='name'/>
                                                </a>
                                        </td>

                                        <td>
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='h2' property='id'/>">
                                                        <jsp:getProperty name='h2' property='name'/>
                                                </a>
                                        </td>

                                        <td>
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='h3' property='id'/>">
                                                        <jsp:getProperty name='h3' property='name'/>
                                                </a>
                                        </td>

                                        <td>
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='h4' property='id'/>">
                                                        <jsp:getProperty name='h4' property='name'/>
                                                </a>
                                        </td>
 				</tr>     
                                
 				<tr>
 					<td><jsp:getProperty name='h1' property='author'/></td>
 					<td><jsp:getProperty name='h2' property='author'/></td>
 					<td><jsp:getProperty name='h3' property='author'/></td>
 					<td><jsp:getProperty name='h4' property='author'/></td>
 				</tr>

 				<tr>
 					<td>$<jsp:getProperty name='h1' property='current_price'/></td>
 					<td>$<jsp:getProperty name='h2' property='current_price'/></td>
 					<td>$<jsp:getProperty name='h3' property='current_price'/></td>
 					<td>$<jsp:getProperty name='h4' property='current_price'/></td>
 				</tr>
 			</table>
 		</div>

 		<div id="recommendB">
 			<div class="titleStyle">Recommendation</div>
 			<table id="rB">
 				<tr>
                                    <td>
                                            <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='r1' property='id'/>">
                                                    <img src="images/bookImages/<jsp:getProperty name='r1' property='id'/>.jpg"/>
                                            </a>
                                    </td>

                                    <td>
                                            <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='r2' property='id'/>">
                                                    <img src="images/bookImages/<jsp:getProperty name='r2' property='id'/>.jpg"/>
                                            </a>
                                    </td>

                                    <td>
                                            <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='r3' property='id'/>">
                                                    <img src="images/bookImages/<jsp:getProperty name='r3' property='id'/>.jpg"/>
                                            </a>
                                    </td>

                                    <td>
                                            <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='r4' property='id'/>">
                                                    <img src="images/bookImages/<jsp:getProperty name='r4' property='id'/>.jpg"/>
                                            </a>
                                    </td>
 				</tr>

 				<tr id="bookName">
 					<td>
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='r1' property='id'/>">
                                                        <jsp:getProperty name='r1' property='name'/>
                                                </a>
                                        </td>

                                        <td>
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='r2' property='id'/>">
                                                        <jsp:getProperty name='r2' property='name'/>
                                                </a>
                                        </td>

                                        <td>
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='r3' property='id'/>">
                                                        <jsp:getProperty name='r3' property='name'/>
                                                </a>
                                        </td>

                                        <td>
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='r4' property='id'/>">
                                                        <jsp:getProperty name='r4' property='name'/>
                                                </a>
                                        </td>
 				</tr>
                                
 				<tr>
 					<td><jsp:getProperty name='r1' property='author'/></td>
 					<td><jsp:getProperty name='r2' property='author'/></td>
 					<td><jsp:getProperty name='r3' property='author'/></td>
 					<td><jsp:getProperty name='r4' property='author'/></td>
 				</tr>

 				<tr>
 					<td>$<jsp:getProperty name='r1' property='current_price'/></td>
 					<td>$<jsp:getProperty name='r2' property='current_price'/></td>
 					<td>$<jsp:getProperty name='r3' property='current_price'/></td>
 					<td>$<jsp:getProperty name='r4' property='current_price'/></td>
 				</tr>
 			</table>
 		</div>

 		<div id="newB">
 			<div class="titleStyle">New</div>
 			<table id="nB">
 				<tr>
                                    <td>
                                            <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='n1' property='id'/>">
                                                    <img src="images/bookImages/<jsp:getProperty name='n1' property='id'/>.jpg"/>
                                            </a>
                                    </td>

                                    <td>
                                            <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='n2' property='id'/>">
                                                    <img src="images/bookImages/<jsp:getProperty name='n2' property='id'/>.jpg"/>
                                            </a>
                                    </td>

                                    <td>
                                            <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='n3' property='id'/>">
                                                    <img src="images/bookImages/<jsp:getProperty name='n3' property='id'/>.jpg"/>
                                            </a>
                                    </td>

                                    <td>
                                            <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='n4' property='id'/>">
                                                    <img src="images/bookImages/<jsp:getProperty name='n4' property='id'/>.jpg"/>
                                            </a>
                                    </td>
 				</tr>

 				<tr id="bookName">
 					<td>
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='n1' property='id'/>">
                                                        <jsp:getProperty name='n1' property='name'/>
                                                </a>
                                        </td>

                                        <td>
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='n2' property='id'/>">
                                                        <jsp:getProperty name='n2' property='name'/>
                                                </a>
                                        </td>

                                        <td>
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='r3' property='id'/>">
                                                        <jsp:getProperty name='r3' property='name'/>
                                                </a>
                                        </td>

                                        <td>
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<jsp:getProperty name='n4' property='id'/>">
                                                        <jsp:getProperty name='n4' property='name'/>
                                                </a>
                                        </td>
 				</tr>
                                
 				<tr>
 					<td><jsp:getProperty name='n1' property='author'/></td>
 					<td><jsp:getProperty name='n2' property='author'/></td>
 					<td><jsp:getProperty name='n3' property='author'/></td>
 					<td><jsp:getProperty name='n4' property='author'/></td>
 				</tr>

 				<tr>
 					<td>$<jsp:getProperty name='n1' property='current_price'/></td>
 					<td>$<jsp:getProperty name='n2' property='current_price'/></td>
 					<td>$<jsp:getProperty name='n3' property='current_price'/></td>
 					<td>$<jsp:getProperty name='n4' property='current_price'/></td>
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