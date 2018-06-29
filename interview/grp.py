
# At CreditKarma we often have to pull customers' credit info from a credit bureau
#   and present them to the customer in a way that they can easily understand.  
#
# Included are credit info and their groupings presented in JSON format. 
#
# 1. The first JSON object contains an array of the customer's credit accounts from a given credit bureau
#   - each account object contains the following attributes:
#     - accountType - enum(visa, amx, master, auto-loan, personal-loan, mortgage, equity)
#     - agencyName - string
#     - balance - number
#     - rate - number
#     - date - string
#   
# 2. The second JSON object contains a tree hierarchy that groups credit accounts by their accountType
#   - each leaf node contains the following attributes
#     - groupId - id
#     - groupName - string
#     - accountTypes - array(visa, amx, master, auto-loan, personal-loan, mortgage, equity)
# 
# Please start implementing in the the following steps:
#  1. Using the given JSON, attach the group name to each account object for the user.
#  2. Display the result grouped by various groups (Loans, Credit Cards etc)
#

# ------------ Sample Output ----------------
#
# ### Accounts ######
#  ### Loan ######
#   Opened a auto-loan with 'Toyota Financial' on 2014-02-15
#   Opened a auto-loan with 'Honda Financial' on 2013-04-15
#   Opened a mortgage with 'BOA' on 2010-10-15
#  ### Credit Card ######
#   Opened a visa with 'CitiBank' on 2005-08-01
#   Opened a master with 'WellsFargo' on 2010-05-01

accounts_by_type = {
  "groupId":3,
  "groupName":"Accounts",
  "children":[
    {
      "groupId":1,
      "groupName":"Loan",
      "accountTypes":["mortgage","auto-loan","personal-loan"]
    },
    {
      "groupId":2,
      "groupName":"Credit Card",
      "accountTypes":["visa","master","amx"]
    }
  ]
}

user_credit_accounts = [
  {
    "accountType":"auto-loan",
    "agencyName":"Toyota Financial",
    "balance":18000,
    "rate":4,
    "date":"2015-08-15"
  },
  {
    "accountType":"auto-loan",
    "agencyName":"Honda Financial",
    "balance":15000,
    "rate":3.5,
    "date":"2014-10-15"
  },
  {
    "accountType":"master",
    "agencyName":"CitiBank",
    "balance":5000,
    "rate":12,
    "date":"2005-08-01"
  },
  {
    "accountType":"visa",
    "agencyName":"Wells Fargo",
    "balance":1000,
    "rate":11,
    "date":"20101-05-01"
  },
  {
    "accountType":"master",
    "agencyName":"Chase",
    "balance":1000,
    "rate":11,
    "date":"20101-05-01"
  },
  {
    "accountType":"master",
    "agencyName":"Bank of West",
    "balance":1000,
    "rate":11,
    "date":"20101-05-01"
  },
  {
    "accountType":"personal-loan",
    "agencyName":"East Bank",
    "balance":80000,
    "rate":5,
    "date":"2012-04-15"
  },
  {
    "accountType":"equity",
    "agencyName":"Chase",
    "balance":80000,
    "rate":5,
    "date":"2012-04-15"
  },
  {
    "accountType":"mortgage",
    "agencyName":"BOA",
    "balance":300000,
    "rate":5,
    "date":"2012-04-15"
  }
]

print ("### %s ######"  % accounts_by_type["groupName"])
for account_type in accounts_by_type["children"]:
    print (" ### %s ######" % account_type["groupName"])
    for account in user_credit_accounts:
        if account["accountType"] in account_type["accountTypes"]:
            print ("  Opened a %s with %s on %s" % (account["accountType"], account["agencyName"], account["balance"]))

