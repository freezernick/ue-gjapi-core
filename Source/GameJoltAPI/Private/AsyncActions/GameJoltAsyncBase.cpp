// Copyright by Nick Lamprecht (2020-2023)


#include "GameJoltAsyncBase.h"

void UGameJoltAsyncBase::Callback(const bool bSuccess, UJsonData* JSON)
{

}

bool UGameJoltAsyncBase::VerifyResponse(const bool bSuccess, UJsonData* JSON)
{
    if(!bSuccess)
    {
        Failure.Broadcast(EGJErrors::RequestFailed);
        return false;
    }
    response = JSON->GetObject("response");
    if(!response)
    {
        Failure.Broadcast(EGJErrors::ResponseInvalid);
        return false;
    }

    bool bResponseSuccess = response->GetBool("success");
    if(!bResponseSuccess)
    {
        FString ResponseMessage = response->GetString("message");
        if(ResponseMessage == "No user could be found matching these credentials.")
            Failure.Broadcast(EGJErrors::CredentialsInvalid);
        else if(ResponseMessage == "No such user with the credentials passed in could be found.")
            Failure.Broadcast(EGJErrors::CredentialsInvalid);
        else if(ResponseMessage == "The game ID you passed in does not point to a valid game.")
            Failure.Broadcast(EGJErrors::GameIDInvalid);
        else if(ResponseMessage == "This key has restrictions placed on it. Please pass in a restriction user with valid permissions.")
            Failure.Broadcast(EGJErrors::RestrictedKey);
        else if(ResponseMessage == "The signature you entered for the request is invalid.")
            Failure.Broadcast(EGJErrors::SignatureInvalid);
        else if(ResponseMessage == "No item with that key could be found.")
            Failure.Broadcast(EGJErrors::KeyNotFound);
        else if(ResponseMessage == "Mathematical operations require the pre-existing data stored to also be numeric.")
            Failure.Broadcast(EGJErrors::OperationFailed);
        else if(ResponseMessage == "Value must be numeric if operation is mathematical.")
            Failure.Broadcast(EGJErrors::OperationFailed);
        else if(ResponseMessage == "GAME JOLT STOP: 0x00000019 (0x00000000, 0xC00E0FF0, 0xFFFFEFD4, 0xC0000000) UNIVERSAL_COLLAPSE")
            Failure.Broadcast(EGJErrors::OperationFailed);
        else if(ResponseMessage == "Incorrect trophy ID.")
            Failure.Broadcast(EGJErrors::InvalidTrophyID);
        else if(ResponseMessage == "The user does not have this trophy.")
            Failure.Broadcast(EGJErrors::TrophyNotAchieved);
        else if(ResponseMessage == "The user already has this trophy.")
            Failure.Broadcast(EGJErrors::TrophyAlreadyAchieved);
        else if(ResponseMessage == "The trophy returned does not belong to this game.")
            Failure.Broadcast(EGJErrors::ParametersInvalidOrUnset);
        else if(ResponseMessage == "Could not get a rank for the parameters you entered.")
            Failure.Broadcast(EGJErrors::ParametersInvalidOrUnset);
        else if(ResponseMessage == "Guests are not allowed to enter scores for this game.")
            Failure.Broadcast(EGJErrors::GuestsNotAllowed);
        else if(ResponseMessage == "You must pass in a user/guest for this score.")
            Failure.Broadcast(EGJErrors::ParametersInvalidOrUnset);
        else if(ResponseMessage == "You must enter a score.")
            Failure.Broadcast(EGJErrors::ParametersInvalidOrUnset);
        else if(ResponseMessage == "You must enter a sort value for this score, and it must be numeric.")
            Failure.Broadcast(EGJErrors::ParametersInvalidOrUnset);
        else if(ResponseMessage == "The high score table ID you passed in does not belong to this game or has been deleted.")
            Failure.Broadcast(EGJErrors::ParametersInvalidOrUnset);
        else if(ResponseMessage == "Could not find an open session. You must open a new one.")
            Failure.Broadcast(EGJErrors::NoSession);
        else if(ResponseMessage == "You must enter in a user ID or username.")
            Failure.Broadcast(EGJErrors::ParametersInvalidOrUnset);
        else if(ResponseMessage == "No such user could be found.")
            Failure.Broadcast(EGJErrors::ParametersInvalidOrUnset);
        else
            Failure.Broadcast(EGJErrors::UnknownError);
        return false;
    }
    return true;
}